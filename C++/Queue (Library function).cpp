#include<iostream>
#include<queue>
using namespace std;

typedef int element;
queue<element> q;

int main()
{
    // q: [ 1 3 5 7 9 ]
    for(int num = 1; num< 10; num+=2)
        q.push(num);
    
    q.pop();    // q: [ 3 5 7 9 ]
    q.pop();    // q: [ 5 7 9 ]
    
    cout <<"q: [ ";
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        cout << cur<< " ";
    }
    cout << "]\n";
    
    return 0;
}

