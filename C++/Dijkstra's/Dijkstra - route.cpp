#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 +1;
const int MAX_N = 1e3 + 1;

priority_queue<pii> pq;
vector <pii> adj[MAX_N];
vector<int> route[MAX_N];

int dist[MAX_N];

int n;  // number of node
int m;  // number of edge

int from, to, weight;
int start, terminal;

void initialize()
{
    for(int i =0; i< MAX_N+1; i++)
        dist[i] = INF;
    
    priority_queue<pii> pq;
    
    for(int i=0; i< MAX_N + 1; i++)
        route[i].clear();
}

void route_update(int cur, int nxt)
{
    route[nxt].clear();
    
    for(auto elem: route[cur])
        route[nxt].push_back(elem);
    
    route[nxt].push_back(cur);
}

void route_print(int start, int end)
{
    cout << start <<"~"<< end <<": " << dist[end]<<"\n";
    
    for(auto elem: route[end])
        cout << elem<<" ";
    cout << end<<"\n";
}

void dijkstra(int s, int e)
{
    initialize();
    
    dist[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        
        if(dist[cur.second] < -1 * cur.first) // optimization
            continue;
        
        for(auto edge : adj[cur.second])
        {
            int next_node = edge.second;
            int next_dist = edge.first + (-1 * cur.first);
            
            if(next_dist < dist[next_node]) //find the faster route
            {
                dist[next_node] = next_dist;
                pq.push({-1*next_dist, next_node});
                route_update(cur.second, next_node); //update the route
            }
        }
    }
    
    route_print(s, e);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    cin >> m;
    
    for(int i=0; i< m; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }
    
    for(int i=0; i<3; i++)
    {
        int start, end;
        cin >> start >> end;
        cout <<"\n";
        dijkstra(start, end);
    }
  
    return 0;
}

/*
 input
 ===
 9
 14
 1 2 10
 1 3 5
 2 3 4
 2 4 7
 3 2 4
 3 5 19
 3 7 24
 4 5 4
 4 7 15
 5 6 4
 5 8 11
 6 7 8
 6 8 5
 7 9 8
 1 2
 2 9
 3 8
 
 result
 ===
 1~2: 9
 1 3 2
 ===
 2~9: 30
 2 4 7 9
 ===
 3~8: 24
 3 2 4 5 6 8
 */
