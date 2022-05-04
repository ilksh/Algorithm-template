#include<iostream>
using namespace std;

const int MAX_SIZE = 10001;

typedef int element;
typedef struct {
    int front;
    int back;
    element array[MAX_SIZE];
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->back = -1;
}

void print(Queue *q)
{
    cout << "q: [ ";
    for(int i= q->front+1; i< q->back+1; i++)
        cout << q->array[i]<<" ";
    cout<<"]\n";
}

bool empty(Queue *q)
{
    // queue is empty
    if(q->front == q->back)
        return true;
    
    else
        return false;
}

bool full(Queue *q)
{
    // queue is saturated
    if(q->back == MAX_SIZE -1)
        return true;
    else
        return false;
}

void push(Queue *q, element item)
{
    if(full(q))
    {
        cout <<"Queue is saturated \n";
        return;
    }
    else
    {
        q->back += 1;
        q->array[q->back] = item;
        print(q);
    }
}

void pop(Queue *q)
{
    if (empty(q))
    {
        cout << "Queue is empty";
        return;
    }
    else
    {
        q->front += 1;
        int result = q->array[q->front];
        cout << result << " was removed\n";
        print(q);
        return;
    }
}

int main()
{
    Queue q;

    push(&q,1); // q: [ 1 ]
    push(&q,2); // q: [ 1 2 ]
    push(&q,5); // q: [ 1 2 5 ]
    pop(&q);    // q: [ 2 5 ]
}

