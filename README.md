# Structure

This branch contains: 
- <a href="/README.md">**README.md**</a> file: this current file which explains the structure of the branch;
- <a href="/ex0 - Normal case for Scheduling">**ex0 - Normal case for Scheduling**</a> file: contains a basic example of the FreeRTOS's scheduling;
- <a href="/ex1-LCD1602">**ex1-LCD1602**</a> file: contains an implementation of an exercise involving LCD;
- <a href="/ex2-LED_with_interrupt">**ex2-LED_with_interrupt**</a> file: contains an implementation of an exercise involving buttons and leds;
- <a href="/ex3-priority_inversion">**ex-3priority_inversion**</a> directory: contains an implementation of an example of priority inversion.


```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
p(point2)
A[README.md];
B[README.md];
C[README.md];
D[README.md];
E[README.md];
p-->A;
p-->dir1([ex0-Normal_case_for_Scheduling]);
p-->dir2([ex1-LCD1602]);
p-->dir3([ex2-LED_with_interrupt]);
p-->dir4([ex3-priority_inversion]);
dir1-->E;
dir3-->B;
dir2-->LED_interrupt;
dir3-->figures_for_README;
dir2-->D;
dir2-->LCD1602
dir4-->C;
dir4-->BIN_SEM;

click p href "https://baltig.polito.it/caos2023/group2/-/tree/point2" "Link to point2";
click BIN_SEM href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/BIN_SEM" "Link to point2";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point2/README.md" "Link to point2.md";
click ex1-LCD1602 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602" "Link to ex1-LCD1602";
click ex2-LED_with_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt" "Link to ex2-LED_with_interrupt";
click ex3-priority_inversion href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion" "Link to ex3-priority_inversion";
click B href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/README.md" "Link to README.md";
click C href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/README.md" "Link to ex3-priority_inversion.md";
click D href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex21-LCD1602/README.md" "Link to LCD1602";
click figures_for_README href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/figures_for_README" "Link to figures_for_README";
click LED_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/LED_interrupt" "Link to LED_interrupt";
click ex3-priority_inversion href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to ex3-priority_inversion";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/README.md" "Link to README.md";
click BIN_SEM href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/BIN_SEM" "Link to BIN_SEM";
```


