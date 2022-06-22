#include<iostream>
using namespace std;

typedef int element;

typedef struct Node{
    element data;
    struct Node *next, *prev;
} Node;

void print(Node* head)
{
    for(Node *p = head->next; p != NULL; p = p->next)
        cout << p->data << "-> ";
    
    cout <<"Null\n";
}

Node* makeNode(element item) {
   Node* newNode = (Node *)malloc(sizeof(Node));
   newNode->data = item;
   newNode->next = NULL;
   newNode->prev = NULL;

   return newNode;
}

void insert_left(Node* head, element item)
{
   Node* p = makeNode(item);
   
   p->next = head->next;
   head->next = p;
   p->prev = head;
}

void insert_right(Node* head, element item)
{
   Node *newNode = makeNode(item);
   Node *cur = head;
   
   while(cur->next) {
      cur = cur->next;
   }

   cur->next = newNode;
   newNode->prev = cur;
}

void pop_left(Node* cur)
{
   Node* temp = cur;

   cur->prev->next = cur->next;
   if(cur->next) cur->next->prev = cur->prev;
   
   free(temp);
}

void pop_right(Node * head)
{
  Node *cur = head, *temp;
    
   while(cur->next) {
      cur = cur->next;
   }

   temp = cur;
   if(cur->prev) cur->prev->next = NULL;
   

   free(temp);
}

int main()
{
     cout <<"====Node1====\n\n";
     cout << "===insert===\n";

     Node* head1 = makeNode(-1);
    
          for(int i=1; i<=5; i++)
     {
         insert_left(head1, i);
         print(head1);
     }
    
    cout << "===pop===\n";
    
     for(int i=1; i<=5; i++)
     {
         pop_left(head1->next);
         print(head1);
     }

    
    cout <<"\n====head2====\n\n";
    cout << "===insert===\n";
    
    Node* head2 = makeNode(-1);
    
    for(int i=100; i>50; i-=10)
    {
        insert_right(head2, i);
        print(head2);
    }
  
    cout << "===pop===\n";
    for(int i=90; i>=50; i-=10)
    {
        pop_right(head2);
        print(head2);
    }
}
/*
 ====Node1====

 ===insert===
 1-> Null
 2-> 1-> Null
 3-> 2-> 1-> Null
 4-> 3-> 2-> 1-> Null
 5-> 4-> 3-> 2-> 1-> Null
 ===pop===
 4-> 3-> 2-> 1-> Null
 3-> 2-> 1-> Null
 2-> 1-> Null
 1-> Null
 Null

 ====head2====

 ===insert===
 100-> Null
 100-> 90-> Null
 100-> 90-> 80-> Null
 100-> 90-> 80-> 70-> Null
 100-> 90-> 80-> 70-> 60-> Null
 ===pop===
 100-> 90-> 80-> 70-> Null
 100-> 90-> 80-> Null
 100-> 90-> Null
 100-> Null
 Null
 */
