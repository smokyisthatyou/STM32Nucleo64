# Structure of the branch

This branch contains: 
- <a href="/README.md">**README.md**</a> file: this current file which explains the structure of the branch;
- <a href="/ex2-LED_with_interrupt">**ex2-LED_with_interrupt**</a> file: contains an implementation of an exercise involving buttons and leds;
- <a href="/ex3-priority_inversion">**ex-3priority_inversion**</a> directory: contains an implementation of an example of priority inversion.


```mermaid
%%{init: {'theme':'base'}}%%
graph LR;
p1(point2)
A[README.md];
B[README.md];
C[README.md];
D[README.md];
p1-->A;
p1-->ex1;
p1-->ex2-LED_with_interrupt;
p1-->ex3-priority_inversion;
ex2-LED_with_interrupt-->C;
ex2-LED_with_interrupt-->LED_interrupt;
ex1-->D;
ex3-priority_inversion --> B;
ex3-priority_inversion --> BIN_SEM;

click p1 href "https://baltig.polito.it/caos2023/group2/-/tree/point1" "Link to point1";
click point1.md href "https://baltig.polito.it/caos2023/group2/-/tree/point1/point1.md" "Link to point1.md";
click dir href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
click pictures href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
```


