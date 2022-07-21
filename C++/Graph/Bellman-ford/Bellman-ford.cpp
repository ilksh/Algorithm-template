#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 5e2 + 2;
const int MAX_M = 6e3 + 3;
const ll INF =  0x3f3f3f3f3f3f3f3f;

int n, m;   // n = number of node, m = number of edge

struct Edge{
    int u,v;    // node1, node2
    ll w;       // weight
};

Edge edge[MAX_M];
ll dist[MAX_N];


bool bellmanFord(int start)
{
    bool isCycle = false;
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    
    // repeat multiple rounds to determine if a negative cycle exists
    for(int round = 0; round < m; ++round){
        bool updated = false;
        
        for(auto& e: edge)
        {
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
                
                // m - 1 repeat means that the shortest path continues to be update
                // there is a negative cycle
                if(round == m-1)
                    isCycle = true;
            }
        }
        if (!updated) break;
    }
    
    return isCycle;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    ll w;
    
    cin >> n >> m;
    
    for(int i=0; i<m; ++i){
        cin >> u >> v >> w;
        edge[i] = {u,v,w};
    }
    
    bool negativeCycle = bellmanFord(1);
    
    if(negativeCycle) cout << -1 << "\n";
    
    else{
        for(int i=2; i<=n; ++i){
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
        }
    }
    
    return 0;
}
