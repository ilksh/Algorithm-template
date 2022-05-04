#include<iostream>
#include<stack>
using namespace std;

typedef int element;
stack <element> s;  // intialize stack

int main()
{
    s.push(1);  // s = [1]
    s.push(2);  // s = [2(top), 1]
    s.push(5);  // s = [5(top), 2, 1]
    s.pop();
   
    // printing from the top
    while(!s.empty())
    {
        auto cur = s.top(); s.pop();
        cout << " "<<cur;
    }
}
