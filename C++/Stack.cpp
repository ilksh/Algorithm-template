#include<iostream>
using namespace std;

const int MAX_N = 10001;

// typedef (variable) element
// variable -> int, char, string…
typedef int element;
typedef struct{
    element array[MAX_N];
    int top;
} Stack;

// initialize stack
void init(Stack *s)
{
    s->top = -1;
}

bool empty(Stack *s)
{
    // stack is empty
    if (s->top == -1)
        return true;
    else
        return false;
}

bool full(Stack *s)
{
    // stack is full
    if (s->top == MAX_N -1)
        return true;
    else
        return false;
}

void push(Stack *s, element item)
{
    if (full(s))
    {
        cout << "Stack is saturated";
        return;
    }
    else
        s->top += 1;
        s->array[s->top] = item;
}

void pop(Stack *s)
{
    if (empty(s))
    {
        cout << "Stack is empty";
        return;
    }
    else
        s->top -=1;
    
}

void print(Stack *s)
{
    if (empty(s))
    {
        cout << "Stack is empty";
        return;
    }
    else
    {
        cout << "s = [ ";
        
        for(int i=0; i< s->top+1; i++)
            cout << s->array[i] <<" ";
        
        cout << "]\n";
    }
}

int main()
{
    Stack s;
    
    init(&s);
    // input data
    push(&s, 1); // s = [1(top) ]
    push(&s, 2); // s = [1, 2(top)]
    push(&s, 3); // s = [1, 2, 3(top)]
    print(&s);
    
    pop(&s);
    print(&s);   //s = [1, 2 (top)]
    
    pop(&s);
    print(&s);   // s = [1 (top)]
    
    return 0;
}





