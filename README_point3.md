# Customization of OS and benchmarks
### FreeRTOS's customization
In this final part of the project we want to modify some of the functions in the Kernel of the operating system FreeRTOS and to benchmark the performance improvement achieved by the
newly implemented solution.  
To do so, we analyzed a particular behaviour that happens in a program where we have three periodic tasks with different priorities (it can also be applied on tasks with same priority)  
- Task 1 with priority = 3, an execution time of 2s and then stopped for 4s;  
- Task 2 with priority = 2, an execution time of 1s and then stopped for 2s;  
- Task 3 with priority = 1, an execution time of 0.5s and then stopped for 0.5s;  

As we can see the third task is the shortest and the most frequent of all.  
If we suppose 
- to work with a cooperative scheduling ( configUSE_PREEMPTION = 0 need to be checked in the *FreeRTOSConfig.h* file), 
- the order of the tasks using the resources is based on the priority {Task 1, Task 2, Task 3} (note it can work with any sequence), then the scheduling will have the following pattern  
**INSERISCI FOTO SCHEDULING** 
<figure align="center">
    <img src="figures_for_README/" width="400"
         alt="Figure 1: scheduling">
    <figcaption>Figure 1: scheduling</figcaption>
</figure>  

As shown in the picture, at time 3.5s Task 3 is stopped and there's an empty space of 0.5 seconds, in which all the tasks are blocked, followed by the resumption of Task 3. This behaviour is also shown by the print in the SWV data console in debug mode of the program *customizeOS* before entering the modifications explained below   
**INSERISCI FOTO SCHEDULING**  
<figure align="center">
    <img src="figures_for_README/" width="400"
         alt="Figure 2: scheduling FREERTOS">
    <figcaption>Figure 2: scheduling FREERTOS</figcaption>
</figure>  

This kind of behaviour is a loss of time since for 0.5 seconds all the tasks are blocked and an inefficient usage of memory since the same TCB is extracted from the CPU, updated and then loaded again. 
To avoid this misbehaviour, we want to modify the function in charge to insert the task in the list of blocked tasks.  
More in detail, we consider the case in which two of the three tasks are already in the block list (as in the case of time 3.5s): we compare the period of time in which the task who's entering the *BlockList*, for example T3, should be delayed *delayTime* with the remaining time that should pass before the first item in the block list is ready to run. If the *delayTime* of T3 is shorter or equal to the remaining time of the other tasks, then we decide to not insert T3 in the *BlockList*, but to let it run until the time of its delay is bigger than the remaining time of the tasks in the *BlockList*; otherwise the task is delayed like the others and we wait for the first task in the *BlockList* to be ready.  
To do so we add in the function *vTaskDelay()* in the *task.c* file the following lines  

```  
#include "list.h"
...
void vTaskDelay( const TickType_t xTicksToDelay )
{
    ...
    TickType_t xCurrentTime = xTaskGetTickCount();
    TCB_t *pxTCB;
    if (listCURRENT_LIST_LENGTH(pxDelayedTaskList) >= 2)
    {
	    ( pxTCB ) = listGET_OWNER_OF_HEAD_ENTRY(pxDelayedTaskList);

	    xNextTaskUnblockTime = listGET_LIST_ITEM_VALUE( &( ( pxTCB )->xStateListItem ) );

	    TickType_t xCurrentTaskUnblockTime = xCurrentTime + xTicksToDelay;
	        
	    if(xCurrentTaskUnblockTime <= xNextTaskUnblockTime)
	    {
	        return;
	    }
    }
... //same code as before the modification 
} 
```  

As writte above, if the current task delay time is shorter or equal to the remaining delay time of the first element in the list then we exit from the *vTaskDelay()* function and the task can continue the execution.

### Benchmarks of the results
Now to do the benchmarks of this implementation we can print on the screen the sequence of tasks and their starting and ending times in order to see if at critical times (like time 3.5s in this example) Task 3 is delayed or not. To do so we must include in the *main.c* file the *stdio.h* and *task.h* files and define the global variable TICKS_PER_SECOND configTICK_RATE_HZ, where configTICK_RATE_HZ is define in the *FreeRTOSConfig.h* file as the number of ticks that occur in 1 second,  to convert the ticks into seconds and milliseconds. After defining the unsigned integer values *seconds* and *milliseconds* we define the function *convertTicksToTime()* which has as parameters  
- TickType_t ticks,  
- unsigned int *seconds,  
- unsigned int *milliseconds  

and converts the ticks into seconds and milliseconds using the variable TICKS_PER_SECOND (equal to 1000)
```
void convertTicksToTime(TickType_t ticks, unsigned int *seconds, unsigned int *milliseconds) 
{
    uint32_t totalMilliseconds = (ticks * 1000) / TICKS_PER_SECOND;
    *seconds = totalMilliseconds / 1000;
    *milliseconds = totalMilliseconds % 1000;
}
```

After that, we need to timestamp for every task the tick of beginning and the tick of ending, convert them into seconds and milliseconds and then print them on the screen.
```
void StartTask(void const *argument)
{
    for(;;)
    {
        TickType_t xLastWakeTime;
	    TickType_t xLastRestTime;
	    xLastWakeTime = xTaskGetTickCount();
	    convertTicksToTime(xLastWakeTime, &seconds, &milliseconds);

	    printf(" Start Task... ");
	    printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);

        ...

        xLastRestTime = xTaskGetTickCount();
	    convertTicksToTime(xLastRestTime, &seconds, &milliseconds);
	    printf(" End Task... ");
	    printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);
    }
}
```

By running the code in the debug mode we can see on the SWV data console that the scheduling of the tasks now is different: at time 3.5s Task 3 is no more delayed but it continues to work until time 5s, when the Task 2 results ready to run, for this reason Task 3 is blocked for 0.5s and Task 2 is the first to start.  
**INSERISCI FOTO SCHEDULING** 
<figure align="center">
    <img src="figures_for_README/" width="400"
         alt="Figure 2: scheduling FREERTOS">
    <figcaption>Figure 2: scheduling FREERTOS</figcaption>
</figure>

In this way we have optimize the usage of time by filling the empty space in the scheduling and by decreasing the number of context switches in those cases when all the tasks could be blocked contemporary.