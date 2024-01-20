## Point 1
Presenting the board and illustrating the process of installation and usage procedures.

# Introduction

ST-Microelectronics is a multinational corporation specialized in the design and manufacture of semiconductor solutions. Established in 1987, the company was created through the merger of two government-owned entities: SGS Microelettronica, an Italian company, and Thomson Semiconducteurs, a French company. Originally named SGS-Thomson Microelectronics, the company later in 1998 changed its name to ST-Microelectronics.

Among the array of products ST produces, we find Microcontrollers and Microprocessors. In the midst of this landscape, the family of STM32 microcontrollers finds its footing. The STM32F4 series can be found among the STM32 MCUs selection. Specifically, within the STM32F446 division, the STM32F446RE microcontroller holds its place.

This particular MCU is usually matched with the STM32 Nucleo-64 Board, which is designed around the microcontroller in a 64-pin LQFP (*Low Profile Quad Flat Package*).

![1](tutorial_pictures/board)
*Figure 1: STM32 NUCLEO-64 Board*

The following diagram illustrates the various hardware features:

![2](tutorial_pictures/board_diagram)
*Figure 2: STM32 NUCLEO-64 Board diagram*

# Installation

The board necessitates certain system requirements. Initially, it is essential to have a device running Windows OS (7, 8, or 10), Linux 64-bit, or MacOS. Additionally, a USB Type-A to Mini-B cable is required to connect the board to the device.

ST-Microelectronics has introduced STM32CubeIDE as the Integrated Development Environment specifically designed for the development of STM32 software. To download the STM32CubeIDE software, it may require users to register on the official ST website at [www.st.com](https://www.st.com). Once registered, users can proceed with the download of STM32CubeIDE-xxx, selecting the appropriate version compatible with their operating system ([Figure 3](3)). It is also possible to select the preferred release, although it's highly recommended to opt for the most recent version when downloading the software.

![3](tutorial_pictures/1)
*Figure 3: STM32CubeIDE softwares*

After completing the download of the software, proceed with the installation by following the displayed instructions.

The user should now connect the board to the device. At this stage, everything is set to initiate a first project. Upon launching the application, a prompt will appear, requesting the definition of a workspace ([Figure 4](4)). One can choose either to select a specific name and position or proceed with the default option provided.

![4](tutorial_pictures/2)
*Figure 4: Creation of a workspace*

The initial step involves logging into myST through the downloaded software. This step is essential for proceeding with future operation.

- *Windows OS users*:
//

- *Linux 64-bit users*:
//

- *MacOS users*:
Search for the "*myST*" tab in the top bar of your display and click on it to unveil the "*Login*" button [Figure 5](5). Then select it to open a window offering options for both already registered users and new ones [Figure 6](6).

![5](tutorial_pictures/3.1)
*Figure 5: Opening the "Login" window*

![6](tutorial_pictures/3.2)
*Figure 6: Loggin into the account*

The first launch of the application will display [Figure 7](7). Subsequent launches will likely present [Figure 8](8). In both scenarios, select "*... new STM32 project*".

![7](tutorial_pictures/4.1)
*Figure 7: Creation of a new STM32 project version 1*

![8](tutorial_pictures/4.2)
*Figure 8: Creation of a new STM32 project version 2*

At this point, you have the option to select the specific MCU or MPU. Alternatively, it is possible to directly choose the board by clicking on "*Board selector*" ([Figure 9](9)) and entering the board name into the "*Commercial Part Number*" field ([Figure 10](10)).

![9](tutorial_pictures/5.1)
*Figure 9: From MCU/MPU selection page to board selection page*

![10](tutorial_pictures/5.2)
*Figure 10: Board name insertion*

After entering the correct board name, the list on the right side of the page will update to display the search match. To proceed, select the option shown ([Figure 11](11)). Once chosen, relevant board information will be displayed, and the "*Next*" button will become available ([Figure 12](12)). Click on it to progress to the following phase.

![11](tutorial_pictures/5.3)
*Figure 11: Selection of the researched board*

![12](tutorial_pictures/5.4)
*Figure 12: Board information and access to the next step*

Next, insert a project name ([Figure 13](13)) and then click on the "*Next*" button, which will become available.

![13](tutorial_pictures/6.1)
*Figure 13: Insertion of a project name*

In the following page click on "*Finish*" to initialize the project ([Figure 14](14)).

![14](tutorial_pictures/6.2)
*Figure 14: Conclusion of the step*

A banner will appear, prompting to select an option ([Figure 15](15)). It is recommended to choose "*Yes*".

![15](tutorial_pictures/6.3)
*Figure 15: Initialization of the project*

