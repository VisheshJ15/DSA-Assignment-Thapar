#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent, rankSet;
int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}
void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x != y) {
        if (rankSet[x] < rankSet[y]) swap(x, y);
        parent[y] = x;
        if (rankSet[x] == rankSet[y]) rankSet[x]++;
    }
}

int KruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    parent.resize(V);
    rankSet.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;
    cout << "\nEdges in Kruskal MST:\n";

    for (auto &e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            unionSet(e.u, e.v);
            mstWeight += e.w;
            cout << e.u << " - " << e.v << " = " << e.w << "\n";
        }
    }
    return mstWeight;
}

int PrimMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first, weight = p.second;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    int mstWeight = 0;
    cout << "\nEdges in Prim MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " = " << key[i] << "\n";
        mstWeight += key[i];
    }
    return mstWeight;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int kruskalWeight = KruskalMST(V, edges);
    cout << "\nTotal weight of Kruskal MST = " << kruskalWeight << endl;

    int primWeight = PrimMST(V, adj);
    cout << "\nTotal weight of Prim MST = " << primWeight << endl;

    return 0;
}