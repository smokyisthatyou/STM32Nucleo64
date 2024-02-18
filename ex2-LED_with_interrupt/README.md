# Example with LED and Interrupt  

In this example it's shown how to update the status of the green LED using the Blue button.  
More in detail, we want that every time the Blue button is pressed the LED changes its status. To do that we link the status of the LED to the value of a counter, which is incremented by 1 with the pressing of the Blue button.The different shapes of the LED are:
- if the counter = 0, then it blinks with a frequency of 0.5 seconds;  
- if the counter = 1, then it remains lit;  
- if the counter = 2, then it remains off;  

When the counter = 3, we start again the cycle by setting the counter equal to zero.  
Since we can press the button at any time, we have to impose that every time the button is pressed, any running task is stopped and the counter is updated. This type of command is performed by an Interrupt, triggered by the pressing of the button. For this reason, the first thing to settle is how to set the blue button as trigger for the interruption.  
In the configuration window, we select the PIN PA5 as GPIO_output for the LED and the PIN PC13 as GPIO\_EXTI13, as shown in Figure 1  

<figure align="center">
    <img src="figures_for_README/es.2.1.png" width="400"
         alt="Figure 1: PIN configuration">
    <figcaption>Figure 1: PIN configuration</figcaption>
</figure>

After that, we check in the GPIO section that the parameters are as shown in Figure 2, and in the NVIC subsection that the EXTI line[15:10] interrupts is Enabled.  

<figure align="center">
    <img src="figures_for_README/es.2.2.png" width="600"
         alt="Figure 2: Interrupt configuration">
    <figcaption>Figure 2: Interrupt configuration</figcaption>
</figure>

This will generate the code:
```
static void MX_GPIO_Init(void)
{
    ...
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    ...
    /* EXTI interrupt init*/
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
```  
The function _HAL_NVIC_SetPriority()_ is part of the Hardware Abstraction Layer (HAL) in the STM32Cube firmware package and it is used to set the priority of a specific interrupt in the Nested Vectored Interrupt Controller (NVIC). It has as parameters:   
- IRQn of the EXTI line. In this case, since the interrupt is linked to the blue button (PIN 13) we must insert the IRQn of the line 13 (which is the same for all the line from 10 to 15) _EXTI15_10_IRQn_;  
- preemption priority, which determines if the interrupt can preempt another interrupt with a lower priority. In this example it's set to 5;  
- subpriority, which allows us to further prioritize the interrupts, when they have the same priority.  

The function _HAL_NVIC_EnableIRQ(EXTI15_10_IRQn)_ is part of the HAL in the STM32Cube firmware package and it is used to enable a specific interrupt in the NVIC, in this case the IRQn of the EXTI line 13, allowing the microcontroller to respond to that interrupt when it occurs.  
After the PIN configuration, we open the _main.c_ file and we include  
```
    #include "main.h"
    #include "cmsis_os.h"
    #include "stm32f446xx.h"
    #include "stm32f4xx_hal_cortex.h"
```
the second one is a template header file containing definition for parameters, threads and other kernel objects and priority values. The third one will be useful to declare the IRQn of the line chosen for the blue button, while the last one includes HAL (Hardware Abstraction Layer) functions related to the use of the interrupts, provided by STMicroelectronics.  
Now we can define the counter variable and the callback function that will be called automatically when an external interrupt (EXTI) occurs on one of the GPIO pins of the STM32 board.  

```
    volatile uint8_t counter = 0;
    void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
```
Moreover we need to declare the _defaultTask_, the task in charge to to control the LED and to modify its status based on the value of a counter:  
```
        osThreadId defaultTaskHandle;
        void StartDefaultTask(void const * argument);
```
Now we can implement the _main()_ function. The functions:  
- _HAL_Init()_;  
- _SystemClock_Config()_;  
- _MX_GPIO_Init()_;  
- _MX_USART2_UART_Init()_;  

are part of the automatic generated code, based on the preferences we chose in the configuration page.  
We have to define the _defaultTask_ and start the scheduling program:  

```
int main(void){
    ...
    osThreadDef(defaultTask, StartDefaultTask, 
                osPriorityRealtime, 0, 128);
    defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
    ...
    osKernelStart();
    }
```
Where  
- _osThreadDef()_ is the macro in charge of defining the parameters of a thread (task) without immediately creating it. The parameters in the round brackets are  
    + task's name  
    + name of the function that will be the thread entry point. This function runs when the thread is started.  
    + priority, where an higher value means an higher priority. In this case we have chosen the priority "osPriorityRealtime" = 5 (maximum value).  
    + number of thread instances that can be created using this definition  
    + stack size (in bytes) allocated for the thread.  
- _osThreadCreate()_ used to create the task with  
    + the type of thread to be created.  
    + a pointer to the argument to pass to the thread function. In this case this value is set to NULL, indicating that no arguments are passed.  
- _osKernelStart()_ starts the RTOS Kernel and begins thread switching.  

Outside the _main()_ function we implement the function for the _defaultTask_:  
```C
void StartDefaultTask(void const * argument) {
  for(;;)
  {
	if(counter = = 0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		osDelay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		osDelay(500);
	}
	else if(counter = = 1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	}
	else if(counter = = 2){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}
	else{
		counter = 0; 
    }}
}
```
To modify the status of the LED we use the function _HAL_GPIO_WritePin()_ which has as parameters:  
- GPIOx, which selects the GPIO peripheral. For the LED we have chosen the GPIOA;  
- GPIO_Pin, which specifies the port bit to be written. For the LED we have chosen the PIN 5;  
- PinState, which specifies the value to be written. More in detail we have  
    + GPIO_PIN_SET = 1 which turns on the LED;  
    + GPIO_PIN_RESET = 0 which turns off the LED.  

Finally, we implement the callback function  
```
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if(GPIO_Pin = = GPIO_PIN_13){
		counter++;
	}
}
```
where we say that if the PIN that causes the interrupt is the PIN associated to the Blue button (in this example is the pin 13) then the counter must be incremented.
