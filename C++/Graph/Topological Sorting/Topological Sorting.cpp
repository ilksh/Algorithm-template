#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int n;      // number of node
int m;      // number of edge
int tc;     // test case
int cnt;    // count the operation to avoid cycle

int inDegree[MAX_N];

vector<int> adj[MAX_N];
queue<int> q;
queue<int> ans;


void initialize()
{
    memset(inDegree, 0, sizeof(inDegree));
    
    for(int i=1; i<n+1; ++i)
        adj[i].clear();
    
    q = queue<int> ();
    ans = queue<int> ();
    cnt = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    
    while(tc--){
        cin >> n >> m;
        
        initialize();
        
        for(int i=0; i<m; ++i){
            int from, to;
            cin >> from >> to;
            
            adj[from].push_back(to);
            inDegree[to]++;
        }
        
        for(int i=1; i<n+1;++i){
            // insert node to queue when indegree of the node is 0.
            if(inDegree[i] == 0){
                q.push(i);
                ans.push(i);
                cnt++;
            }
        }
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            
            // search all adjacent nodes
            for(auto e:adj[cur])
            {
                if(--inDegree[e] == 0)
                {
                    q.push(e);
                    ans.push(e);
                    cnt++;
                }
            }
        }
        
        // cycle exists
        if(cnt < n)
            cout << "Error: cycle exists\n";
        
            
        // cycle doesn't exist
        else{
            cout << "topological sorting sequence: ";
            while(!ans.empty()){
                int cur = ans.front(); ans.pop();
                cout << cur << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}

//2
//8 9
//1 2
//1 3
//2 4
//3 5
//3 6
//5 4
//6 7
//7 8
//8 4
//6 7
//1 2
//1 3
//2 4
//3 4
//4 5
//5 6
//6 4
