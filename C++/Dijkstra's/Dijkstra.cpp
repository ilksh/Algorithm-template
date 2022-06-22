#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

const int INF = 1e9;
const int MAX_V = 2 * 1e4 + 1;

priority_queue<pii> pq;    // distance, node
vector<pii> adj[MAX_V];    // adjacency list

// The minimum cost to the ith node is dp[i]
int dp[MAX_V+1];

void fill_adj()
{
    // adj[from].push_back({weight, to})
    // the route from node1 to node2 takes as much time as weight
    adj[1].push_back({10, 2});
    adj[1].push_back({20, 3});
    adj[1].push_back({50, 4});
    adj[2].push_back({7,3});
    adj[2].push_back({30, 4});
    adj[3].push_back({40, 4});
    adj[3].push_back({43, 5});
    adj[3].push_back({8, 2});
    adj[4].push_back({15, 5});
}

void dijkstra()
{
    int start_node = 1;
    dp[start_node] = 0;
    pq.push({0, start_node});
    
    while (!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        
        if(dp[cur.second] != (-1) * cur.first)
            continue;
        
        // search all nodes which are connected to the current node
        for(pii edge:adj[cur.second])
        {
            // edge = (weight, node)
            int next = edge.second;
            int next_weight = (-1 * cur.first) + edge.first;
            // if the cost of new route is lower than that of current
            if (next_weight < dp[next])
            {
                // update information
                dp[next] = next_weight;
                pq.push({-1*dp[next], next});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i< MAX_V; i++)
        dp[i] = INF;
    
    fill_adj();
    dijkstra();
    
    for(int i=1; i<6; i++)
        cout << i<<": "<<dp[i]<<"\n";
}
