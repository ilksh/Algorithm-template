## Test Case 1
```mermaid
  graph LR;
  1--->2 ;
  1--->3 ;
  2--->4 ;
  3--->5 ;
  3--->6 ;
  5--->4 ;
  6--->7 ;
  7--->8 ;
  8--->4 ;
 ```
 ### Cycle doesn't exist
 ### Sequence
 ---
 ```mermaid
    graph LR;
    1--->2;
    2--->3;
    3--->5;
    5--->6;
    6--->7;
    7--->8;
    8--->4;
 ```
 ---
 ## Test Case 2
 ```mermaid
    graph LR;
    1--->2;
    1--->3;
    2--->4;
    3--->4;
    4--->5;
    5--->6;
    6--->4;
```
### Cycle exists
---
 ```mermaid
    graph LR;
    4--->5;
    5--->6;
    6--->4;
```
