#include<iostream>
using namespace std;

const int MAX_SIZE = 5;

typedef int element;
typedef struct{
    element array[MAX_SIZE];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

bool empty(Queue *q)
{
    if(q->front == q->rear)
        return true;
    return false;
}

void print(Queue *q)
{
    if (empty(q))
    {
        cout <<"Queue is empty \n";
        return;
    }
    
    cout << "(front: "<< q->front << " rear: "<< q->rear <<")\n";
    cout << "q: [ ";
    
    // Initial idx is front
    int idx = q->front;
    do
    {
        idx = (idx+1) % MAX_SIZE;
        cout << q->array[idx]<< " ";
        if (idx == q->rear)
            break;
    } while(idx!= q->front);
    cout<<"]\n";
}

bool full(Queue *q)
{
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return true;
    return false;
}

void enqueue(Queue *q, element item)
{
    if (full(q))
    {
        cout <<"Queue is saturated \n";
        return;
    }
    // maintaining the shape of a circular queue using the operator %
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->array[q->rear] = item;
}

void deque(Queue *q)
{
    if(empty(q))
    {
        cout << "Queue is empty";
        return;
    }
    
    q->front = (q->front + 1) % MAX_SIZE;
    int result = q->array[q->front];
    cout<< result<< " was removed\n";
    
  
}

int main()
{
    Queue q;
    
    init(&q);
    cout << "===Input data===\n\n";
    int num = 10;
    while(!full(&q))
    {
        enqueue(&q, num);
        print(&q);
        num += 20;
        cout << "\n";
    }
    
    cout << "\n===Delete data===\n\n";
    while(!empty(&q))
    {
        deque(&q);
        print(&q);
        cout << "\n";
    }
    
    return 0;
}
/*
 ===Input data===

 (front: 0 rear: 1)
 q: [ 10 ]

 (front: 0 rear: 2)
 q: [ 10 30 ]

 (front: 0 rear: 3)
 q: [ 10 30 50 ]

 (front: 0 rear: 4)
 q: [ 10 30 50 70 ]


 ===Delete data===

 10 was removed
 (front: 1 rear: 4)
 q: [ 30 50 70 ]

 30 was removed
 (front: 2 rear: 4)
 q: [ 50 70 ]

 50 was removed
 (front: 3 rear: 4)
 q: [ 70 ]

 70 was removed
 Queue is empty
 */
