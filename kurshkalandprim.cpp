#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rankv;

    DSU(int n) : parent(n), rankv(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b){ return a.w < b.w; });

    DSU dsu(V);

    int mst_cost = 0;
    cout << "Kruskal MST edges:\n";

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            cout << e.u << " -- " << e.v << "  (" << e.w << ")\n";
            mst_cost += e.w;
            dsu.unite(e.u, e.v);
        }
    }

    cout << "Total MST Cost = " << mst_cost << endl;
}

void prim(int V, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});  // {weight, node}

    int mst_cost = 0;

    cout << "Prim MST edges:\n";

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mst_cost += w;

        cout << "Pick node " << u << " with cost " << w << endl;

        for (auto &nbr : adj[u]) {
            int v = nbr.first;
            int weight = nbr.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Total MST Cost = " << mst_cost << endl;
}

