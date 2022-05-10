#include<iostream>
using namespace std;

const int MAX_SIZE = 5;

typedef int element;
typedef struct{
    element array[MAX_SIZE];
    int front, rear;
} Deque;

void init(Deque *dq)
{
    dq->front = dq->rear = 0;
}

bool empty(Deque *dq)
{
    if (dq->front == dq->rear)
        return true;
    return false;
}

bool full(Deque *dq)
{
    if( (dq->rear + 1) % MAX_SIZE == dq->front)
        return true;
    return false;
}

void print(Deque *dq)
{
    if (empty(dq))
       {
           cout <<"Queue is empty \n";
           return;
       }
       
       cout << "(front: "<< dq->front << " rear: "<< dq->rear <<")\n";
       cout << "dq: [ ";
       
       // Initial idx is front
       int idx = dq->front;
       do
       {
           idx = (idx+1) % MAX_SIZE;
           cout << dq->array[idx]<< " ";
           if (idx == dq->rear)
               break;
       } while(idx!= dq->front);
       cout<<"]\n\n";
}

// append-rear
void append(Deque *dq, element item)
{
    if(full(dq))
    {
        cout << "Deque is satuarated\n";
        return;
    }
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->array[dq->rear] = item;
}

// append-front
void appendleft(Deque *dq, element item)
{
    if(full(dq))
    {
        cout << "Deque is satuarated\n";
        return;
    }
    
    dq->array[dq->front] = item;
    dq->front = ((dq->front - 1)+MAX_SIZE) % MAX_SIZE;
}

// pop-rear
void pop(Deque *dq)
{
    if(empty(dq))
    {
        cout << "Deque is empty\n";
        return;
    }
    
    int past = dq->rear;
    cout << dq->array[past]<<" was removed\n";
    
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
}

// pop-front
void popleft(Deque *dq)
{
    if(empty(dq))
    {
        cout << "Deque is empty\n";
        return;
    }
    dq->front = (dq->front + 1) % MAX_SIZE;
    int result = dq->array[dq->front];
    cout << result << " was removed\n";
}

int main()
{
    Deque dq;
    Deque dq2;
    
    init(&dq);
    init(&dq2);
    
    cout << "===Input Data (append)===\n\n";
    for(int i=1; i<10; i+=2)
    {
        append(&dq, i);
        print(&dq);
    }
    
    cout<<"\n===Delete Data (pop)===\n\n";
    while(!empty(&dq))
    {
        pop(&dq);
        print(&dq);
    }
    
    cout << "\n===Input Data (appendleft)===\n\n";
    for(int i=1; i<10; i+=2)
    {
        appendleft(&dq2, i);
        print(&dq2);
    }
    
    cout<<"\n===Delete Data (popleft)===\n\n";
    while(!empty(&dq2))
    {
        popleft(&dq2);
        print(&dq2);
    }
    
}
/*
 ===Input Data (append)===

 (front: 0 rear: 1)
 dq: [ 1 ]

 (front: 0 rear: 2)
 dq: [ 1 3 ]

 (front: 0 rear: 3)
 dq: [ 1 3 5 ]

 (front: 0 rear: 4)
 dq: [ 1 3 5 7 ]

 Deque is satuarated
 (front: 0 rear: 4)
 dq: [ 1 3 5 7 ]


 ===Delete Data (pop)===

 7 was removed
 (front: 0 rear: 3)
 dq: [ 1 3 5 ]

 5 was removed
 (front: 0 rear: 2)
 dq: [ 1 3 ]

 3 was removed
 (front: 0 rear: 1)
 dq: [ 1 ]

 1 was removed
 Queue is empty

 ===Input Data (appendleft)===

 (front: 4 rear: 0)
 dq: [ 1 ]

 (front: 3 rear: 0)
 dq: [ 3 1 ]

 (front: 2 rear: 0)
 dq: [ 5 3 1 ]

 (front: 1 rear: 0)
 dq: [ 7 5 3 1 ]

 Deque is satuarated
 (front: 1 rear: 0)
 dq: [ 7 5 3 1 ]


 ===Delete Data (popleft)===

 7 was removed
 (front: 2 rear: 0)
 dq: [ 5 3 1 ]

 5 was removed
 (front: 3 rear: 0)
 dq: [ 3 1 ]

 3 was removed
 (front: 4 rear: 0)
 dq: [ 1 ]

 1 was removed
 Queue is empty
 */
