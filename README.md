# Structure 
This branch contains: 
- <a href="/README.md">**README.md**</a> file: this current file which explains the structure of the branch;
- <a href="/point1.md">**point1.md**</a> file: which contains the development of BoardOS project Point 1;
- <a href="/tutorial_pictures">**tutorial_pictures**</a> directory: which contains all the pictures used in point.md.


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
click dir href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
click pictures href "https://baltig.polito.it/caos2023/group2/-/tree/point1/tutorial_pictures" "Link to tutorial_pictures";
```


