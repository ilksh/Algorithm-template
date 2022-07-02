#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10001;

typedef int element;
typedef struct {
    int front;
    int rear;
    element array[MAX_SIZE];
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void print(Queue *q)
{
    cout << "q: [ ";
    for(int i= q->front+1; i< q->rear+1; i++)
        cout << q->array[i]<<" ";
    cout<<"]\n";
}

bool empty(Queue *q)
{
    // queue is empty
    if(q->front == q->rear)
        return true;
    
    return false;
}

bool full(Queue *q)
{
    // queue is saturated
    if(q->rear == MAX_SIZE -1)
        return true;
    
    return false;
}

void enqueue(Queue *q, element item)
{
    if(full(q))
    {
        cout <<"Queue is saturated \n";
        return;
    }
    
    q->rear += 1;
    q->array[q->rear] = item;
    print(q);
}

void dequeue(Queue *q)
{
    if (empty(q))
    {
        cout << "Queue is empty";
        return;
    }
    
    q->front += 1;
    int result = q->array[q->front];
    cout << result << " was removed\n";
    print(q);
    return;
}

int main()
{
    Queue q;

    enqueue(&q,1); // q: [ 1 ]
    enqueue(&q,2); // q: [ 1 2 ]
    enqueue(&q,5); // q: [ 1 2 5 ]
    dequeue(&q);    // q: [ 2 5 ]
}

