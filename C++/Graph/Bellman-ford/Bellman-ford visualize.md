# Test Case 1
```mermaid
  graph LR;
  1-->|3|2;
  1-->|4|3;
  2-->|-1|4;
  3-->|-2|2;
  3-->|6|4;
 ```
 ---
 ## Round 1
|idx|dist|
|--|--------|
|d[1]|0|
|d[2]|3 -> 2|
|d[3]|4|
|d[4]|2|
---
## Round 2
|idx|dist|
|--|--------|
|d[1]|0|
|d[2]|2|
|d[3]|4|
|d[4]|1|
---
## Round 3
|idx|dist|
|--|--------|
|d[1]|0|
|d[2]|2|
|d[3]|4|
|d[4]|1|
---
### TC 1: No negative cycle exists because information update is not done in round 3
---
# Test Case 2
``` mermaid
  graph LR;
  1--->|7|2;
  1--->|3|3;
  2--->|-1|5;
  2--->|-3|1;
  3--->|-2|4;
  4--->|1|2;
  5--->|4|4;
  ```
---
## Round 1
|idx|dist|
|--|--------|
|d[1]|0|
|d[2]|7 -> 2|
|d[3]|3|
|d[4]|1|
|d[5]|6|
---
## Round 2
|idx|dist|
|--|--------|
|d[1]|0 -> -1|
|d[2]|2|
|d[3]|3|
|d[4]|1|
|d[5]|1|
---
## Round 3
|idx|dist|
|--|--------|
|d[1]|-1|
|d[2]|1|
|d[3]|2|
|d[4]|0|
|d[5]|1|
---
## Round 4
|idx|dist|
|--|--------|
|d[1]|-1 -> -2|
|d[2]|1|
|d[3]|2|
|d[4]|0|
|d[5]|1->0|
---
## Round 5
|idx|dist|
|--|--------|
|d[1]|-2|
|d[2]|0|
|d[3]|2 -> 1|
|d[4]|-1|
|d[5]|0|
---
## Round 6
|idx|dist|
|--|--------|
|d[1]|-2 -> -3|
|d[2]|0|
|d[3]|1|
|d[4]|-1|
|d[5]|0 -> -1|
---
## Round 7
|idx|dist|
|--|--------|
|d[1]|-3|
|d[2]|0 -> -1|
|d[3]|1 -> 0|
|d[4]|-1 -> -2|
|d[5]|-1|
---
### Test Case 2: Negative cycle exists because the information continues to be updated
