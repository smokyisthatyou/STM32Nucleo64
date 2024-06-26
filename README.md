# GUIDE

This README.md file contains an illustration of the project structure and its objectives to allow users to efficiently surf through the various branches.

## 

The aim of the project is to acquire proficiency in the usage of an embedded system on an ST Nucleo Board, specifically STM32 Nucleo-64 Board paired with STM32F446RE MCU.

This project contains the following 5 branches which serve to a specified scope:

| BRANCH    | Objectives |
| --------  | ---------- |
| **boardOS**    | It contains a ***guide*** explaining the structure, the project ***report*** and ***presentation***.  |
| **point1**     | It contains a ***tutorial*** detailing the installation and usage procedures.                         |
| **point2**     | It contains defining practical ***examples*** illustrating the functionalities of the board.          |
| **point3_and_4**     | It contains a ***customization*** of the operating system and ***benchmarks*** of the performances achieved by the newly implemented solution.  |
    
Each branch contains a README.md file which better explains its internal structure.

Here is a diagram displaying the contents of each branch. For further information, please refer to the specific branch README.md file.

[comment]: <> (change names or file format for files and add href!!)
[comment]: <> (orientation options: graph LR, graph TD)
[comment]: <> (color options: base, default)


```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
b(boardOS)
b-->README.md;
b-->report.pdf;   
b-->reportLatex.zip;         
b-->presentation.pptx;
b-->presentation.pdf;

click b href "https://baltig.polito.it/caos2023/group2/-/tree/boardOS" "Link to boardOS";
click report.pdf href "https://baltig.polito.it/caos2023/group2/-/tree/boardOS/report.pdf" "Link to report.pdf";
click reportLatex.zip href "https://baltig.polito.it/caos2023/group2/-/tree/boardOS/reportLatex.zip" "Link to reportLatex.zip";
click presentation.pptx href "https://baltig.polito.it/caos2023/group2/-/tree/boardOS/presentation.pptx" "Link to presentation.pptx";
click presentation.pdf href "https://baltig.polito.it/caos2023/group2/-/tree/boardOS/presentation.pdf" "Link to presentation.pdf";


```

&nbsp;

```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
p1(point1)
p1-->README.md;
p1-->point1.md;
p1-->dir([tutorial_pictures]);
pictures["board.png <br>board_diagram.png <br>1.png <br>2.png <br>3_1.png <br>3_2.png <br>4_1.png <br>4_2.png <br>5_1.png <br>5_2.png <br>5_4.png <br>6_1.png <br>6_2.png <br>6_3.png <br>7.png <br>8_1.png <br>8_2.png <br>8_3.png <br>9_1.png <br>9_2.png <br>9_3.png <br>10_1.png <br>10_2.png"]
dir([tutorial_pictures])-->pictures;

click p1 href "https://baltig.polito.it/caos2023/group2/-/tree/point1" "Link to point1";
click point1.md href "https://baltig.polito.it/caos2023/group2/-/tree/point1/point1.md" "Link to point1.md";
click README.md href "https://baltig.polito.it/caos2023/group2/-/blob/point1/README.md" "Link to README.md";
click dir href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
click pictures href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
```

&nbsp;

```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
A[README.md];
B[README.md];
C[README.md];
D[README.md];
E[README.md];
p2(point2)
p2-->dir4([ex0-Normal_Case_for_Scheduling]);
p2-->A;
p2-->dir1([ex1-LCD1602]);
p2-->dir2([ex2-LED_with_interrupt]);
p2-->dir3([ex3-priority_inversion]);
dir1-->LCD1602;
dir1-->D;
dir2-->LED_interrupt;
dir2-->B;
dir2-->figures_for_README;
dir3-->BIN_SEM;
dir3-->C;
dir3-->priority_inversion;
dir4-->E

click A href "https://baltig.polito.it/caos2023/group2/-/tree/point2/README.md" "Link to README.md";
click p2 href "https://baltig.polito.it/caos2023/group2/-/tree/point2" "Link to point2";
click README.md href "https://baltig.polito.it/caos2023/group2/-/blob/point2/README.md" "Link to README.md";
click dir2 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt" "Link to ex2-LED_with_interrupt";
click LED_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/LED_interrupt" "Link to LED_interrupt";
click B href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/README.md" "Link to README.md";
click figures_for_README href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/figures_for_README" "Link to figures_for_README";
click dir3 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion";
click BIN_SEM href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/BIN_SEM";
click priority_inversion href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/priority_inversion";
click C href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/README.md" "Link to README.md";
click dir1 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602" "Link to ex1-LCD1602";
click D href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602/README.md" "Link to README.md";
click LCD1602 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602/LCD1602" "Link to LCD1602";
click dir4 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex0-Normal_Case_for_Scheduling" "Link to ex0-Normal_Case_for_Scheduling";
click E href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex0-Normal_Case_for_Scheduling/README.md" "Link to README.md";
```

&nbsp;

```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
p3(point3_and_4)
p3-->customizeOS;
p3-->README.md;
p3-->dir6([figures_for_README]);

click p3 href "https://baltig.polito.it/caos2023/group2/-/tree/point3_and_4" "Link to point3_and_4";
click customizeOS href "https://baltig.polito.it/caos2023/group2/-/tree/point3_and_4/customizeOS" "Link to customizeOS";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point3_and_4/README_point3.md" "Link to README.md";
click dir6 href "https://baltig.polito.it/caos2023/group2/-/tree/point3_and_4/figures_for_README" "Link to figures_for_README";
```

&nbsp;

