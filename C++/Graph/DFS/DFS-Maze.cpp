#include<bits/stdc++.h>
using namespace std;

// s = start, e = end
// 0 = path, 1 = wall
char maze[7][8]= {
{'s','0','1','1','1','1','1','1'},
{'1','0','0','0','1','0','0','1'},
{'1','1','0','1','0','0','1','1'},
{'1','1','0','1','0','0','0','1'},
{'1','0','0','0','0','1','0','e' },
{'1','1','0','1','1','1','1','1'},
};

// delta y, x
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
bool visited[7][8];

int cnt;
int flag;

int OOB(int y, int x);

void maze_print()
{
    cout <<"=step"<<cnt<<"  =\n";
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<8; j++)
            cout << maze[i][j];
        cout <<"\n";
    }
}

void dfs(int row, int col)
{
    visited[row][col] = true;
    
    cnt++;
    maze[row][col] = 'x';
    
    maze_print();
    
    for(int dir = 0; dir<4; dir++)
    {
        int new_row = row + dy[dir];
        int new_col = col + dx[dir];
    
        if(OOB(new_row, new_col))
            continue;
        
        if (maze[new_row][new_col] == 'e')
        {
            flag = true;
            cout << "Find the exit!!\n";
            cout << "Search: "<< cnt<<" times\n";
            exit(0);
        }
        
        if(!visited[new_row][new_col] && maze[new_row][new_col] == '0')
            dfs(new_row, new_col);
            
    }
}



int main()
{
    dfs(0,0);
    
    if(!flag)
    {
        cout << "Couldn't find the exit!!\n";
        cout << "Search: "<< cnt<<" times\n";
    }
        
}

// Out Of Boundary
int OOB(int y, int x)
{
    return y<0 || y>=7 || x<0 || x>=8;
}

