# Example Scheduling of FreeRTOS



## Overview

The example is to show how the default scheduling of FreeRTOS works: a preemptive scheduling based on priority, hence higher priority tasks, when ready, can preempt lower priority tasks. 
After the operation osKernelStart() in the main function, the control is given to the scheduler and the scheduling algorithm. 
There are three main tasks: high, medium and low priority. 
The first task chosen by the scheduler is the high priority task, which is executed 3 times before ending  with osTaskExit().
Then it will be the turn for the medium task and subsequently for the low task, and both will do the same thing as the high priority task.

<figure align="center">
    <img src="Immages/aa.png" width="580"
         alt="Figure 1: tasks">
    <figcaption>Figure 1: tasks</figcaption>
</figure>

I also take the TaskProfiler is used in the code, it will be treated as if it were an uint8_t type. 
So this TaskProfiler main duty is count how many times tasks run and print them 
I also added some lines in code syscall.c for printf use in debugging by selecting port0

For code :
1. I declares three variables of type uint8_t (thanks to the typedef aliasing) named Task1_Profiler, Task2_Profiler, and Task3_Profiler, which are presumably used for profiling tasks in the program.
2. I creates three tasks (Task1, Task2, and Task3) with corresponding handles (Task1Handle, Task2Handle, and Task3Handle) using the osThreadNew function, each with its own start function (StartTask1, StartTask2, StartTask3).
3. The StartTask1 , StartTask2, StartTask3 function runs an infinite loop where it increments Task1_Profiler, Task2_Profiler, Task3_Profiler prints its current value along with a message indicating it's from Task-1,Task-2,Task-3 and exits the thread if Task1_Profiler,Task2_Profiler,Task3_Profiler reaches a value of 3 or greater. 

For debugging :
In syscall.c I added void ITM_SendChar(uint8_t ch)
{
	DEMCR |= (1<<24);

	ITM_TRACE_EN |= (1<<0);

	while(!(ITM_STIMULUS_PORT0 & 1));

	ITM_STIMULUS_PORT0 = ch;
} 

This function is used to send a character (ch) over the Instrumentation Trace Macrocell (ITM) interface for debugging purposes, enabling the ITM trace and waiting until the port is ready before transmitting the character.
Then click on debug and select windows after this select SHOW VIEW after then select SWV then select SWV ITM CONSOLE 
Debug window will open and and select on cinfig. then select port 0 and run .
Its showing in screen 
TASK-1 0
TASK-1 1 
TASK-1 2
TASK-1 3
TASK-2 0
TASK-2 1 
TASK-2 2
TASK-2 3
TASK-3 0
TASK-3 1 
TASK-3 2
TASK-3 3


