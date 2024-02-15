# Priority Inversion

This project has been developed using STM32CubeIDE. 

Hercules has been used as a serial port terminal to catch the data transmitted via the UART (Universal Asynchronous Receiver/Transmitter). 

stm32cubeide: https://www.st.com/en/development-tools/stm32cubeide.html

hercules (available for windows only): https://www.hw-group.com/software/hercules-setup-utility


## Overview 

This exercise consist of three tasks with different priorities (HighTask, NormalTask and LowTask) and a binary semaphore.

The user button of the Nucleo64 board is used to release the semaphore, firstly taken by the high priority task. 

## Setup

## Execution
Here a more detailed explanation of how the flow of execution proceed, and how this program is specifically written to culminate in a priority inversion case. 
### High Task

The HighTask is the first one that the scheduler takes from the ready queue and begins its execution. 

``` 
void Starthightask(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
	  char *str1 = "Entered HighTask and waiting for semaphore\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen (str1), 100);

	  osSemaphoreWait(BinSemHandle, osWaitForever);

	  char *str3 = "Semaphore acquired by HighTask\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen (str3), 100);

	  char *str2 = "Leaving HighTask and releasing Semaphore \n\n";
	  HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen (str2), 100);

	  osSemaphoreRelease(BinSemHandle);
	  osDelay(500);
  }
}
``` 

It transmits a string and than waits for the semaphore to be taken. Now the sempahore is free, so once the task succeed it transmit two other messages and then release the semaphore. Lastly it begins a waiting period of half a second to permit the execution of the other two tasks with lower priority.

### Medium task
After the execution of the high task, the medium priority task starts: 

``` 
void Startnormaltask(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
	  char *str1 = "Entered NormalTask\n";
	  	 	  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen (str1), 100);

	  	 	  char *str2 = "LeavingNormalTask\n\n";
	  	 	  HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen (str2), 100);

	  	 	  osDelay(500);
  }
}
```
This task only trasmit two messages, one to informt that it's starting, one to inform it's ending. 

After that it also begins a waiting period. 

### Low Prioriy task
Now it's time for the lower priority task. 

```
void Startlowtask(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
	  char *str1 = "Entered LowTask and waiting for semaphore\n";
	 	 	  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen (str1), 100);

	 	 	  osSemaphoreWait(BinSemHandle, osWaitForever);

	 	 	  char *str3 = "Semaphore acquired by LowTask\n";
	 	 	  HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen (str3), 100);

	 	 	  while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)); //wait till the pin go low

	 	 	  char *str2 = "Leaving LowTask and releasing Semaphore \n\n";
	 	 	  HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen (str2), 100);

	 	 	  osSemaphoreRelease(BinSemHandle);

	 	 	  osDelay(500);

  }
}
```
This third task is the more complex one: after transmitting a message it acquires the semaphore. After that it begin to wait untile the PIN13 (the one associated to the user button) go low, in other words untile the button is pressed. 

At this time the low priority task is preempte by the higher priority task once it ends it waiting stage of 500 ms. 

Now, high task has to wait for the semaphore to be realsed, since it is still acquired by the low priority task. 

Medium priority task will resume and preempt the low priority task. It has no need for the semaphore to run, so it will start and end. 

Now both the high and the low task are waiting for something (the first one for the semaphore the second for the button to be pressed), so medium task will execute every 500 ms.

Now the important point: *even if i press the button the low task has to wait the medium task to finish its execution. High task will also have to wait for medium task to finish.* Here the priority inversion: the highest priority task to resume it execution has to wait for the medium and the low priority task to finish. 

When the button is pressed, low task will continue its execution and release the semaphore, (after the end of medium task). High task will execute from the waiting point. Then the medium task will run. Now high task execute acquiring and realising the semaphore. At this point medium task should run, but it is suspended for 500ms, so low task begins. It acquire the semaphore and wait for the event. In the meantime medium task will have finished it waiting time so it preempts low task. After waiting for the 500 ms, high task will resume and try to acquire the semaphore,but it has to wait. From now on medium task will preempt the low task every 500ms, as happened in the begging before the button was pressed. 

Here a snippet of what the serial terminal Hercules is able to capture during execution: 


