### Binary Tree
```mermaid
graph TD;
  1-->|Left|2;
  1-->|Right|3;
  
  2-->|Left|4;
  2-->|Right|5;
  
  3-->|Left|6;
```
---
### Preorder
```mermaid
graph LR;
  1-->2-->4-->5-->3-->6;
```
---
### Inorder
```mermaid
graph LR;
  4-->2-->5-->1-->6-->3;
```
---
### Postorder
```mermaid
graph LR;
  4-->5-->2-->6-->3-->1;
```
