#include<bits/stdc++.h>
using namespace std;
void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, 
                  vector<pair<int,int>>, 
                  greater<pair<int,int>>> pq;

    pq.push({0, src});  // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra Distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };

    addEdge(0,1,2);
    addEdge(0,3,6);
    addEdge(1,2,3);
    addEdge(1,3,8);
    addEdge(1,4,5);
    addEdge(2,4,7);

    cout << "\n=== Dijkstra ===\n";
    dijkstra(V, adj, 0);

    return 0;
}
