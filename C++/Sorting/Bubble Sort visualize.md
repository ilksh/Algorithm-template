```mermaid
   graph LR;
   9---7;
   7---12;
   12---5;
   5---21;
   21---8
 ```
 ---
 ## i = 5
 
 - j = 0
 - swap(list[0], list[1])
 
```mermaid
   graph LR;
   7---9;
   9---12;
   12---5;
   5---21;
   21---8
 ```

 - j = 1
 - no change
 
```mermaid
   graph LR;
   7---9;
   9---12;
   12---5;
   5---21;
   21---8
 ```
 
 - j = 2
 - swap(list[2], list[3])
 
```mermaid
   graph LR;
   7---9;
   9---5;
   5---12;
   12---21;
   21---8
 ```
 
 - j = 3
 - no change
 
```mermaid
   graph LR;
   7---9;
   9---5;
   5---12;
   12---21;
   21---8
 ```
 
 - j = 4
 - swap(list[4], list[5])
 
```mermaid
   graph LR;
   7---9;
   9---5;
   5---12;
   12---8;
   8---21
 ```
---
## i = 4

 - j = 0
 - no change
 
```mermaid
   graph LR;
   7---9;
   9---5;
   5---12;
   12---8;
   8---21
 ```
 
 - j = 1
 - swap(list[1], list[2])
 
```mermaid
   graph LR;
   7---5;
   5---9;
   9---12;
   12---8;
   8---21
 ```
 
 - j = 2
 - no change
 
```mermaid
   graph LR;
   7---5;
   5---9;
   9---12;
   12---8;
   8---21
 ```
 
 - j = 3
 - swap(list[3], list[4])
 
```mermaid
   graph LR;
   7---5;
   5---9;
   9---8;
   8---12;
   12---21
 ```
 ---
 ## i =3
 - j = 0
 - swap(list[0], list[1])
 
```mermaid
   graph LR;
   5---7;
   7---9;
   9---8;
   8---12;
   12---21
 ```
 
 - j = 1
 - no change
 
 ```mermaid
   graph LR;
   5---7;
   7---9;
   9---8;
   8---12;
   12---21
 ```
 
 - j = 2
 - swap(list[2], list[3])
 
```mermaid
   graph LR;
   5---7;
   7---8;
   8---9;
   9---12;
   12---21
 ```
 ---
 ## i = 2
 
 - j = 0
 - no change
 
```mermaid
   graph LR;
   5---7;
   7---8;
   8---9;
   9---12;
   12---21
 ```
 - j = 1
 - no change
 
```mermaid
   graph LR;
   5---7;
   7---8;
   8---9;
   9---12;
   12---21
 ```
 ---
  ## i = 1
 
 - j = 0
 - no change
 
```mermaid
   graph LR;
   5---7;
   7---8;
   8---9;
   9---12;
   12---21
 ```
 
