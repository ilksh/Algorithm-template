#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool visited[15];
vector <int> adj[15];
queue<int> ans;

void adj_check()
{
    // adj[1][2,6,7,9]
    adj[1].push_back(2);
    adj[1].push_back(6);
    adj[1].push_back(7);
    adj[1].push_back(9);
    
    //adj[2][3,4]
    adj[2].push_back(3);
    adj[2].push_back(4);
    
    //adj[4][5]
    adj[4].push_back(5);
    
    //adj[7][8]
    adj[7].push_back(8);
}

void dfs(int cur)
{
    visited[cur] = true;
    ans.push(cur);
    
    for(auto elem: adj[cur])
    {
        if(!visited[elem])
            dfs(elem);
    }
}

void ans_print()
{
    cout << "search order\n";
    cout << ans.front(); ans.pop();
    while(!ans.empty())
    {
        int cur = ans.front(); ans.pop();
        cout << "->"<<cur;
    }
    cout <<"\n";
}
           
int main()
{
    adj_check();
    dfs(1);
    ans_print();
    exit(0);
}

