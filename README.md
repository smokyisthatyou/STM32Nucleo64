# Structure

This branch contains: 
- <a href="/README.md">**README.md**</a> file: this current file which explains the structure of the branch;
- <a href="/ex1_LCD1602">**ex1_LCD1602**</a> file: contains an implementation of an exercise involving LCD;
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
p-->A;
p-->ex1_LCD1602;
p-->ex2-LED_with_interrupt;
p-->ex3-priority_inversion;
ex2-LED_with_interrupt-->B;
ex2-LED_with_interrupt-->LED_interrupt;
ex1_LCD1602-->D;
ex1_LCD1602-->LCD1602
ex3-priority_inversion --> C;
ex3-priority_inversion --> BIN_SEM;

click p href "https://baltig.polito.it/caos2023/group2/-/tree/point2" "Link to point2";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point2/README.md" "Link to point2.md";
click ex1-LCD1602 href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex1_LCD1602" "Link to ex1_LCD1602";
click ex2-LED_with_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt" "Link to ex2-LED_with_interrupt";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/README.md" "Link to README.md";
click LED_interrupt href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex2-LED_with_interrupt/LED_interrupt" "Link to LED_interrupt";
click ex3-priority_inversion href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to ex3-priority_inversion";
click README.md href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/README.md" "Link to README.md";
click BIN_SEM href "https://baltig.polito.it/caos2023/group2/-/tree/point2/ex3-priority_inversion/BIN_SEM" "Link to BIN_SEM";
```


