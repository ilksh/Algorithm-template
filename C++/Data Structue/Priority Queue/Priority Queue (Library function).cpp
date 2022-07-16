#include<bits/stdc++.h>
using namespace std;

typedef int element;
priority_queue<element> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num[6] = {17, 5, 10, 19, 21, 8};
    
    for(auto data : num){
        pq.push(data);
    }
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        
        cout << cur << " ";
    }
}

