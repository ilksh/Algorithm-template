# Priority Queue (max heap)
## 2 rules
- 1. Parent node should be bigger than its child node
- 2. Maintain Complete binary tree
---
### Push
- current status
```mermaid
   graph TD;
   21-->19;
   19-->11;
   19-->9;
   21-->7;
```
- insert 18 (initial)
```mermaid
   graph TD;
   21-->19;
   21-->7;
   19-->11;
   19-->9;
   7-->18;
```
- Follow rule no.1
```mermaid
   graph TD;
   21-->19;
   21-->18;
   19-->11;
   19-->9;
   18-->7;
```
