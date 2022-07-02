```mermaid
graph LR;
  1-->|10|2;
  1-->|20|3;
  1-->|50|4;
  2-->|30|4;
  2-->|7|3;
  3-->|8|2;
  3-->|40|4;
  3-->|43|5;
  4-->|15|5;
```
  ---
  ### Result
  ---
  #### Node 1
  - time: 0
  ---
  #### Node 2
  - time: 10
  ```mermaid
  graph LR;
    1-->|10|2;
  ```
  ---
#### Node 3
- time: 17
```mermaid
graph LR;
  1-->|10|2;
  2-->|7|3;
```
---
#### Node 4
- time: 40
```mermaid
graph LR;
  1-->|10|2;
  2-->|30|4;
```
---
#### Node 4
- time: 55
```mermaid
graph LR;
  1-->|10|2;
  2-->|30|4;
  4-->|15|5;
```
  
