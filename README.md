# Structure

This branch contains: 
- <a href="/README.md">**README.md**</a> file: this current file which explains the structure of the branch;
- <a href="/ex0 - Normal case for Scheduling">**ex0 - Normal case for Scheduling**</a> directory: contains a basic example of the FreeRTOS's scheduling;
- <a href="/ex1-LCD1602">**ex1-LCD1602**</a> directory: contains an implementation of an exercise involving LCD;
- <a href="/ex2-LED_with_interrupt">**ex2-LED_with_interrupt**</a> directory: contains an implementation of an exercise involving buttons and leds;
- <a href="/ex3-priority_inversion">**ex-3priority_inversion**</a> directory: contains an implementation of an example of priority inversion.

```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
A[README.md];
B[README.md];
C[README.md];
D[README.md];
p2(point2)
p2-->dir4([ex0-Normal Case for Scheduling]);
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

click A href "https://baltig.polito.it/caos2023/group2/-/tree/point2/README.md" "Link to README.md";
click p2 href "https://baltig.polito.it/caos2023/group2/-/tree/point2" "Link to point2";
click README.md href "https://baltig.polito.it/caos2023/group2/-/blob/point2/README.md" "Link to README.md";
click dir2 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt" "Link to ex2-LED_with_interrupt";
click LED_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/LED_interrupt" "Link to LED_interrupt";
click B href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_Interrupt/README.md" "Link to README.md";
click figures_for_README href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/figures_for_README" "Link to figures_for_README";
click dir3 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion";
click BIN_SEM href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/BIN_SEM";
click priority_inversion href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/priority_inversion";
click C href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/README.md" "Link to README.md";
click dir1 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602" "Link to ex1-LCD1602";
click D href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602/README.md" "Link to README.md";
click LCD1602 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1-LCD1602/LCD1602" "Link to LCD1602";
```


