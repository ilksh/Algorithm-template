#include<iostream>
#include<queue>
using namespace std;

bool visited[15];
bool adj_mtrx[15][15];
queue<int> q;
queue<int> ans;

void adj_check()
{
    // node 1 and 2 are connected
    adj_mtrx[1][2] = true;
    adj_mtrx[2][1] = true;
    
    // node 1 and 6 are connected
    adj_mtrx[1][6] = true;
    adj_mtrx[6][1] = true;
    
    // node 1 and 7 are connected
    adj_mtrx[1][7] = true;
    adj_mtrx[7][1] = true;
    
    // node 1 and 9 are connected
    adj_mtrx[1][9] = true;
    adj_mtrx[9][1] = true;
    
    // node 2 and 3 are connected
    adj_mtrx[2][3] = true;
    adj_mtrx[3][2] = true;
    
    // node 2 and 4 are connected
    adj_mtrx[2][4] = true;
    adj_mtrx[4][2] = true;
    
    // node 4 and 5 are connected
    adj_mtrx[4][5] = true;
    adj_mtrx[5][4] = true;
    
    // node 7 and 8 are connected
    adj_mtrx[7][8] = true;
    adj_mtrx[8][7] = true;
}

void bfs(int num)
{
    visited[num] = true;
    q.push(num);
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        visited[cur] = true;
        //cout << "->"<<cur;
        ans.push(cur);
        for(int i=1; i<10; i++)
        {
            if(!visited[i] && adj_mtrx[cur][i])
                q.push(i);
        }
        
    }
}

void ans_print()
{
    cout << "bfs search order\n";
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
    bfs(1);
    ans_print();
    exit(0);
}

