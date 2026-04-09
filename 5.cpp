#include <bits/stdc++.h> using namespace std; 
#define P pair<int,int> 
// ---------- Prim's Algorithm ---------- int prim(int V, vector<vector 
>& adj) { priority_queue<P, vector 
, greater 
> pq; vector visited(V, false); 
pq.push({0, 0}); 
int cost = 0; 
 
while (!pq.empty()) { 
    auto [wt, u] = pq.top(); 
    pq.pop(); 
 
    if (visited[u]) continue; 
 
    visited[u] = true; 
    cost += wt; 
 
    for (auto [v, w] : adj[u]) { 
        if (!visited[v]) 
            pq.push({w, v}); 
    } 
} 
return cost; 
  
} 
// ---------- Kruskal's Algorithm ---------- struct Edge { int u, v, w; }; 
vector parent, rankv; 
int findSet(int x) { if (parent[x] != x) parent[x] = findSet(parent[x]); return parent[x]; } 
void unionSet(int a, int b) { a = findSet(a); b = findSet(b); 
if (a != b) { 
    if (rankv[a] < rankv[b]) 
        swap(a, b); 
    parent[b] = a; 
    if (rankv[a] == rankv[b]) 
        rankv[a]++; 
} 
  
} 
int kruskal(int V, vector& edges) { sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return 
a.w < b.w; }); 
parent.resize(V); 
rankv.resize(V, 0); 
 
for (int i = 0; i < V; i++) 
    parent[i] = i; 
 
int cost = 0; 
 
for (auto e : edges) { 
    if (findSet(e.u) != findSet(e.v)) { 
        unionSet(e.u, e.v); 
        cost += e.w; 
    } 
} 
return cost; 
  
} 
// ---------- Main Function ---------- int main() { int V = 4; 
// Adjacency list for Prim 
vector<vector<P>> adj(V); 
 
adj[0].push_back({1, 10}); 
adj[1].push_back({0, 10}); 
 
adj[0].push_back({2, 6}); 
adj[2].push_back({0, 6}); 
 
adj[0].push_back({3, 5}); 
adj[3].push_back({0, 5}); 
 
adj[1].push_back({3, 15}); 
adj[3].push_back({1, 15}); 
 
adj[2].push_back({3, 4}); 
adj[3].push_back({2, 4}); 
 
// Edge list for Kruskal 
vector<Edge> edges = { 
    {0,1,10}, {0,2,6}, {0,3,5}, 
    {1,3,15}, {2,3,4} 
}; 
 
cout << "Prim MST cost: " << prim(V, adj) << endl; 
cout << "Kruskal MST cost: " << kruskal(V, edges) << endl; 
 
return 0; 
  
}
