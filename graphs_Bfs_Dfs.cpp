#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v);
        if (!directed) 
            adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS : ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next])
                DFSUtil(next, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS : ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int V, E;
    bool directed;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Directed graph? (1 = yes, 0 = no): ";
    cin >> directed;

    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}
