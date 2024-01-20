## Point 1
Presenting the board and illustrating the process of installation and usage procedures.

# Introduction

ST-Microelectronics is a multinational corporation specialized in the design and manufacture of semiconductor solutions. Established in 1987, the company was created through the merger of two government-owned entities: SGS Microelettronica, an Italian company, and Thomson Semiconducteurs, a French company. Originally named SGS-Thomson Microelectronics, the company later in 1998 changed its name to ST-Microelectronics.

Among the array of products ST produces, we find Microcontrollers and Microprocessors. In the midst of this landscape, the family of STM32 microcontrollers finds its footing. The STM32F4 series can be found among the STM32 MCUs selection. Specifically, within the STM32F446 division, the STM32F446RE microcontroller holds its place.

This particular MCU is usually matched with the STM32 Nucleo-64 Board, which is designed around the microcontroller in a 64-pin LQFP (*Low Profile Quad Flat Package*).

<figure>
    <img src="/tutorial_pictures/board.png" width="200"
         alt="Figure 1: STM32 NUCLEO-64 Board">
    <figcaption>Figure 1: STM32 NUCLEO-64 Board</figcaption>
</figure>

The following diagram illustrates the various hardware features:

<figure>
    <img src="/tutorial_pictures/board_diagram.png" width="200"
         alt="Figure 1: STM32 NUCLEO-64 Board">
    <figcaption>Figure 2: STM32 NUCLEO-64 Board diagram</figcaption>
</figure>

# Installation

The board necessitates certain system requirements. Initially, it is essential to have a device running Windows OS (7, 8, or 10), Linux 64-bit, or MacOS. Additionally, a USB Type-A to Mini-B cable is required to connect the board to the device.

ST-Microelectronics has introduced STM32CubeIDE as the Integrated Development Environment specifically designed for the development of STM32 software. To download the STM32CubeIDE software, it may require users to register on the official ST website at [www.st.com](https://www.st.com). Once registered, users can proceed with the download of STM32CubeIDE-xxx, selecting the appropriate version compatible with their operating system (<a href="/tutorial_pictures/1.png">Figure 3</a>). It is also possible to select the preferred release, although it's highly recommended to opt for the most recent version when downloading the software.

<figure>
    <img src="/tutorial_pictures/1.png" width="200"
         alt="Figure 3: STM32CubeIDE softwares">
    <figcaption>Figure 3: STM32CubeIDE softwares</figcaption>
</figure>

After completing the download of the software, proceed with the installation by following the displayed instructions.

The user should now connect the board to the device. At this stage, everything is set to initiate a first project. Upon launching the application, a prompt will appear, requesting the definition of a workspace (<a href="/tutorial_pictures/2.png">Figure 4</a>). One can choose either to select a specific name and position or proceed with the default option provided.

<figure>
    <img src="/tutorial_pictures/2.png" width="200"
         alt="Figure 4: Creation of a workspace">
    <figcaption>Figure 4: Creation of a workspace</figcaption>
</figure>

The initial step involves logging into myST through the downloaded software. This step is essential for proceeding with future operation.

- *Windows OS users*:
//

- *Linux 64-bit users*:
//

- *MacOS users*:
Search for the "*myST*" tab in the top bar of your display and click on it to unveil the "*Login*" button (<a href=“/tutorial_pictures/3.1.png”>Figure 5</a>). Then select it to open a window offering options for both already registered users and new ones (<a href=“/tutorial_pictures/3.2.png”>Figure 6</a>).

<figure>
    <img src="/tutorial_pictures/3.1.png" width="200"
         alt="Figure 5: Opening the "Login" window">
    <figcaption>Figure 5: Opening the "Login" window</figcaption>
</figure>

<figure>
    <img src="/tutorial_pictures/3.2.png" width="200"
         alt="Figure 6: Loggin into the account">
    <figcaption>Figure 6: Loggin into the account</figcaption>
</figure>

The first launch of the application will display <a href=“/tutorial_pictures/4.1.png”>Figure 7</a>. Subsequent launches will likely present <a href=“/tutorial_pictures/4.2.png”>Figure 8</a>. In both scenarios, select "*... new STM32 project*".

<figure>
    <img src="/tutorial_pictures/4.1.png" width="200"
         alt="Figure 7: Creation of a new STM32 project version 1">
    <figcaption>Figure 7: Creation of a new STM32 project version 1</figcaption>
</figure>

<figure>
    <img src="/tutorial_pictures/4.2.png" width="200"
         alt="Figure 8: Creation of a new STM32 project version 2">
    <figcaption>Figure 8: Creation of a new STM32 project version 2</figcaption>
</figure>

At this point, you have the option to select the specific MCU or MPU. Alternatively, it is possible to directly choose the board by clicking on "*Board selector*" (<a href=“/tutorial_pictures/5.1.png”>Figure 9</a>) and entering the board name into the "*Commercial Part Number*" field (<a href=“/tutorial_pictures/5.2.png”>Figure 10</a>).

<figure>
    <img src="/tutorial_pictures/5.1.png" width="200"
         alt="Figure 9: From MCU/MPU selection page to board selection page">
    <figcaption>Figure 9: From MCU/MPU selection page to board selection page</figcaption>
</figure>

<figure>
    <img src="/tutorial_pictures/5.2.png" width="200"
         alt="Figure 10: Board name insertion">
    <figcaption>Figure 10: Board name insertione</figcaption>
</figure>

After entering the correct board name, the list on the right side of the page will update to display the search match. To proceed, select the option shown (<a href=“/tutorial_pictures/5.3.png”>Figure 11</a>). Once chosen, relevant board information will be displayed, and the "*Next*" button will become available (<a href=“/tutorial_pictures/5.4.png”>Figure 12</a>). Click on it to progress to the following phase.

<figure>
    <img src="/tutorial_pictures/5.3.png" width="200"
         alt="Figure 11: Selection of the researched board">
    <figcaption>Figure 11: Selection of the researched board</figcaption>
</figure>

<figure>
    <img src="/tutorial_pictures/5.4.png" width="200"
         alt="Figure 12: Board information and access to the next step">
    <figcaption>Figure 12: Board information and access to the next step</figcaption>
</figure>

Next, insert a project name (<a href=“/tutorial_pictures/6.1.png”>Figure 13</a>) and then click on the "*Next*" button, which will become available.

<figure>
    <img src="/tutorial_pictures/6.1.png" width="200"
         alt="Figure 13: Insertion of a project name">
    <figcaption>Figure 13: Insertion of a project name</figcaption>
</figure>

In the following page click on "*Finish*" to initialize the project (<a href=“/tutorial_pictures/6.2.png”>Figure 14</a>).

<figure>
    <img src="/tutorial_pictures/6.2.png" width="200"
         alt="Figure 14: Conclusion of the step">
    <figcaption>Figure 14: Conclusion of the step</figcaption>
</figure>

A banner will appear, prompting to select an option (<a href=“/tutorial_pictures/6.3.png”>Figure 15</a>). It is recommended to choose "*Yes*".

<figure>
    <img src="/tutorial_pictures/6.3.png" width="200"
         alt="Figure 15: Initialization of the project">
    <figcaption>Figure 15: Initialization of the project</figcaption>
</figure>

