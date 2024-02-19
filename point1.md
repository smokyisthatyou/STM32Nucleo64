# Point 1
Presenting the board and illustrating the process of installation and usage procedures.

## Introduction

ST-Microelectronics is a multinational corporation specialized in the design and manufacture of semiconductor solutions. Established in 1987, the company was created through the merger of two government-owned entities: SGS Microelettronica, an Italian company, and Thomson Semiconducteurs, a French company. Originally named SGS-Thomson Microelectronics, the company later in 1998 changed its name to ST-Microelectronics.

Among the array of products ST produces, we find Microcontrollers and Microprocessors. In the midst of this landscape, the family of STM32 microcontrollers finds its footing. The STM32F4 series can be found among the STM32 MCUs selection. Specifically, within the STM32F446 division, the STM32F446RE microcontroller holds its place.

This particular MCU is usually matched with the STM32 Nucleo-64 Board, which is designed around the microcontroller in a 64-pin LQFP (*Low Profile Quad Flat Package*).

<figure align="center">
    <img src="/tutorial_pictures/board.png" width="350"
         alt="Figure 1: STM32 NUCLEO-64 Board">
    <figcaption>Figure 1: STM32 NUCLEO-64 Board</figcaption>
</figure>

The following diagram illustrates the various hardware features:

<figure align="center">
    <img src="/tutorial_pictures/board_diagram.png" width="630"
         alt="Figure 2: STM32 NUCLEO-64 Board diagram">
    <figcaption>Figure 2: STM32 NUCLEO-64 Board diagram</figcaption>
</figure>

## Installation

The board necessitates certain system requirements. Initially, it is essential to have a device running Windows OS (7, 8, or 10), Linux 64-bit, or MacOS. Additionally, a USB Type-A to Mini-B cable is required to connect the board to the device.

ST-Microelectronics has introduced STM32CubeIDE as the Integrated Development Environment specifically designed for the development of STM32 software. To download the STM32CubeIDE software, it may require users to register on the official [ST website](https://www.st.com). Once registered, users can proceed with the download of STM32CubeIDE-xxx, selecting the appropriate version compatible with their operating system (<a href="/tutorial_pictures/1.png">Figure 3</a>). It is also possible to select the preferred release, although it's highly recommended to opt for the most recent version when downloading the software.

<figure align="center">
    <img src="/tutorial_pictures/1.png" width="800"
         alt="Figure 3: STM32CubeIDE softwares">
    <figcaption>Figure 3: STM32CubeIDE softwares</figcaption>
</figure>

After completing the download of the software, proceed with the installation by following the displayed instructions.

## Project creation

The user should now connect the board to the device. At this stage, everything is set to initiate a first project. Upon launching the application, a prompt will appear, requesting the definition of a workspace (<a href="/tutorial_pictures/2.png">Figure 4</a>). One can choose either to select a specific name and position or proceed with the default option provided.

<figure align="center">
    <img src="/tutorial_pictures/2.png" width="500"
         alt="Figure 4: Creation of a workspace">
    <figcaption>Figure 4: Creation of a workspace</figcaption>
</figure>

The initial step involves logging into myST through the downloaded software. This step is essential for proceeding with future operation.

Search for the `myST` tab in the top bar of your display and click on it to unveil the `Login` button (<a href="/tutorial_pictures/3_1.png">Figure 5.3</a>). Then select it to open a window offering options for both already registered users and new ones (<a href="/tutorial_pictures/3_2.png">Figure 6</a>).

<figure align="center">
    <img src="/tutorial_pictures/3_1.png" width="150"
         alt="Figure 5.3: Opening the &quot;Login window&quot; on MacOS">
    <figcaption>Figure 5.3: Opening the "Login window" on MacOS</figcaption>
</figure>

<figure align="center">
    <img src="/tutorial_pictures/3_2.png" width="600"
         alt="Figure 6: Logging into the account">
    <figcaption>Figure 6: Logging into the account</figcaption>
</figure>

The first launch of the application will display <a href="/tutorial_pictures/4_1.png">Figure 7</a>. Subsequent launches will likely present <a href="/tutorial_pictures/4_2.png">Figure 8</a>. In both scenarios, select `... new STM32 project`.

<figure align="center">
    <img src="/tutorial_pictures/4_1.png" width="900"
         alt="Figure 7: Creation of a new STM32 project version 1">
    <figcaption>Figure 7: Creation of a new STM32 project version 1</figcaption>
</figure>

<figure align="center">
    <img src="/tutorial_pictures/4_2.png" width="900"
         alt="Figure 8: Creation of a new STM32 project version 2">
    <figcaption>Figure 8: Creation of a new STM32 project version 2</figcaption>
</figure>

At this point, you have the option to select the specific MCU or MPU. Alternatively, it is possible to directly choose the board by clicking on `Board selector` (<a href="/tutorial_pictures/5_1.png">Figure 9</a>) and entering the board name into the "*Commercial Part Number*" field (<a href="/tutorial_pictures/5_2.png">Figure 10</a>).

<figure align="center">
    <img src="/tutorial_pictures/5_1.png" width="900"
         alt="Figure 9: From MCU/MPU selection page to board selection page">
    <figcaption>Figure 9: From MCU/MPU selection page to board selection page</figcaption>
</figure>

<figure align="center">
    <img src="/tutorial_pictures/5_2.png" width="900"
         alt="Figure 10: Board name insertion">
    <figcaption>Figure 10: Board name insertion</figcaption>
</figure>

After entering the correct board name, the list on the right side of the page will update to display the search match. To proceed, select the option shown (<a href="/tutorial_pictures/5_3.png">Figure 11</a>). Once chosen, relevant board information will be displayed, and the `Next` button will become available (<a href="/tutorial_pictures/5_4.png">Figure 12</a>). Click on it to progress to the following phase.

<figure align="center">
    <img src="/tutorial_pictures/5_3.png" width="900"
         alt="Figure 11: Selection of the researched board">
    <figcaption>Figure 11: Selection of the researched board</figcaption>
</figure>

<figure align="center">
    <img src="/tutorial_pictures/5_4.png" width="900"
         alt="Figure 12: Board information and access to the next step">
    <figcaption>Figure 12: Board information and access to the next step</figcaption>
</figure>

Next, insert a project name (<a href="/tutorial_pictures/6_1.png">Figure 13</a>) and then click on the `Next` button, which will become available.

<figure align="center">
    <img src="/tutorial_pictures/6_1.png" width="500"
         alt="Figure 13: Insertion of a project name">
    <figcaption>Figure 13: Insertion of a project name</figcaption>
</figure>

In the following page click on `Finish` to initialize the project (<a href="/tutorial_pictures/6_2.png">Figure 14</a>).

<figure align="center">
    <img src="/tutorial_pictures/6_2.png" width="500"
         alt="Figure 14: Conclusion of the step">
    <figcaption>Figure 14: Conclusion of the step</figcaption>
</figure>

A banner will appear, prompting to select an option (<a href="/tutorial_pictures/6_3.png">Figure 15</a>). It is recommended to choose `Yes`.

<figure align="center">
    <img src="/tutorial_pictures/6_3.png" width="500"
         alt="Figure 15: Initialization of the project">
    <figcaption>Figure 15: Initialization of the project</figcaption>
</figure>

The following window (<a href="/tutorial_pictures/6_3.png">Figure 16</a>) will be now displayed. Here it is possible to change the board configurations.

<figure align="center">
    <img src="/tutorial_pictures/7.png" width="900"
         alt="Figure 16: Pinout & Configuration">
    <figcaption>Figure 16: Pinout & Configuration</figcaption>
</figure>

The OS currently installed on the board is [FreeRTOS](https://www.freertos.org) V10.3.1, which is a real-time operating system (RTOS) for microcontrollers and small microprocessors.
FreeRTOS allows the user to structure the project in tasks which group sets of instructions. To add a task at this stage, search for the `FREERTOS` button (<a href="/tutorial_pictures/8_1.png">Figure 17</a> arrow n.1) in the left column and select it to unveil the "*FREERTOS Mode and Configuration*" window. Now click on the `Tasks and Queues` button  (<a href="/tutorial_pictures/8_1.png">Figure 17</a> arrow n.2) to reveal the corresponding tab. As shown in <a href="/tutorial_pictures/8_1.png">Figure 17</a>, there is already a *DefaultTask* created which the user can later modify. Select the `Add` button (<a href="/tutorial_pictures/8_1.png">Figure 17</a> arrow n.3) to proceed with the creation of a new task.

<figure align="center">
    <img src="/tutorial_pictures/8_1.png" width="900"
         alt="Figure 17: Creation of a new task">
    <figcaption>Figure 17: Creation of a new task</figcaption>
</figure>

A window called "*New Task*" (<a href="/tutorial_pictures/8_2.png">Figure 18</a>) will be opened allowing the user to set the specifications for the new task. It is also possible to set a priority which will be used if a prioritized preemptive scheduling algorithm will be selected.

<figure align="center">
    <img src="/tutorial_pictures/8_2.png" width="300"
         alt="Figure 18: New Task window">
    <figcaption>Figure 18: New Task window</figcaption>
</figure>

FreeRTOS provides three different scheduling algorithms:
- Prioritized preemptive scheduling with time slicing;
- Prioritized preemptive scheduling without time slicing;
- Cooperative scheduling.

At this stage, it is only possible to choose whether to enable or not the preemptive scheduling algorithm. To do so, click on the `Config parameters` button (<a href="/tutorial_pictures/8_3.png">Figure 19</a> arrow n.1) which can be found in the "*FREERTOS Mode and Configuration*" window, in the `FREERTOS` section. The tab will display different categories, search for the `Kernel settings` entry. The first item in the list is "*USE_PREEMPTION*" which if set to `Enabled` will result in the selection of a preemptive scheduling algorithm, on the contrary if set to `Disabled` a cooperative scheduling algorithm will be used. The default value of this parameter is `Enabled` (<a href="/tutorial_pictures/8_3.png">Figure 19</a> arrow n.2), simply click on it to display the `Disabled` option.

<figure align="center">
    <img src="/tutorial_pictures/8_3.png" width="900"
         alt="Figure 19: &quot;USE_PREEMPTION&quot; parameter">
    <figcaption>Figure 19: "USE_PREEMPTION" parameter</figcaption>
</figure>

**If changes have been made**, it is necessary to save the project and generate the code that matches the modifications. Look for the `💾` button (<a href="/tutorial_pictures/9_1.png">Figure 20</a>) at the top-left corner of the screen and click on it.

<figure align="center">
    <img src="/tutorial_pictures/9_1.png" width="200"
         alt="Figure 20: Save button">
    <figcaption>Figure 20: Save button</figcaption>
</figure>

A question window will appear, select `Yes` (<a href="/tutorial_pictures/9_2.png">Figure 21</a>) to generate the code.

<figure align="center">
    <img src="/tutorial_pictures/9_2.png" width="500"
         alt="Figure 21: Code generation window">
    <figcaption>Figure 21: Code generation window</figcaption>
</figure>

Select the `Yes` option (<a href="/tutorial_pictures/9_3.png">Figure 22</a>) in the following window as well to display the code associated perspective.

<figure align="center">
    <img src="/tutorial_pictures/9_3.png" width="500"
         alt="Figure 22: Open associated perspective window">
    <figcaption>Figure 22: Open associated perspective window</figcaption>
</figure>

The `main.c` file will now be opened.

**If changes have not been made**, in order to display the `main.c` file expand the project directory on the left in the "*Project Explorer*" window (<a href="/tutorial_pictures/10_1.png">Figure 23</a>), then open `Core` and after unfold `Src`. The `main.c` will be te second item in the list.

<figure align="center">
    <img src="/tutorial_pictures/10_1.png" width="900"
         alt="Figure 23: &quot;main.c&quot; location">
    <figcaption>Figure 23: "main.c" location"</figcaption>
</figure>

STM32CubeIDE provides the [CMSIS (*Common Microcontroller Software Interface Standard*)](https://www.arm.com/technologies/cmsis) which simplifies microcontroller software development providing a consistent and efficient interface for developers working with Cortex-M and entry-level Cortex-A processors.

Scrolling through the `main.c` it is possible to observe CMSIS commands for tasks management. Any task is composed by three code segments (the example below is for *DefaultTask* hence those lines of code can be found only if it has not been deleted. Any task created has the same format, but different parameters values and implementation):

- **Task function prototype**, before the main function
```C++
/*in the private function prototypes section*/
void StartDefaultTask(void const * argument);
```

- **Task definition and creation**, in the main function
```C++
/* Create the thread(s) */
/* definition and creation of defaultTask */
osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
```

- **Task function implementation**, after the main function
```C++
/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}
```

If the user wants to add a new task, it is recommended to manually insert it by adapting the format above. Using the "*Pinout & Configuration*" window (accessible by double clicking on the .ioc file in the "*Project Explorer*" window) to add the task will result in the re-generation of the code and will most likely erase any customization of the code implemented by the user.

As illustrated before, FreeRTOS provides three types of scheduling algorithms. To select the desired one, open `FreeRTOSConfig.h` (<a href="/tutorial_pictures/10_2.png">Figure 24</a>).

<figure align="center">
    <img src="/tutorial_pictures/10_2.png" width="900"
         alt="Figure 24: &quot;main.c&quot; location">
    <figcaption>Figure 24: "FreeRTOSConfig.h" location"</figcaption>
</figure>

Locate the line:
```C++
#define configUSE_PREEMPTION
```
Use the following combinations to configure the scheduler as desired:

| configUSE_PREEMPTION   | configUSE_TIME_SLICING |
| ---------------------  | ---------------------- |
| 1                      | 1 or undefined         |
| 1                      | 0                      |
| 0                      | any value              |

Note: "configUSE_TIME_SLICING" is usually not defined; define it if needed using:
```C++
#define configUSE_TIME_SLICING
```
