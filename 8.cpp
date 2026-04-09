#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
  
void bfs(int start, const vector<vector<int>>& adj, vector<int>& visited) { 
    queue<int> q; 
    visited[start] = 1; 
    q.push(start); 
    cout << "BFS Traversal: "; 
    while (!q.empty()) { 
        int node = q.front(); q.pop(); 
        cout << node << " "; 
        for (int i = 0; i < adj.size(); i++) 
            if (adj[node][i] && !visited[i]) { q.push(i); visited[i] = 1; } 
    } 
    cout << "\n"; 
} 
  
void dfs(int node, const vector<vector<int>>& adj, vector<int>& visited) { 
    visited[node] = 1; 
    cout << node << " "; 
    for (int i = 0; i < adj.size(); i++) 
        if (adj[node][i] && !visited[i]) dfs(i, adj, visited); 
} 
  
int main() { 
    int n, start; 
    cout << "Enter number of vertices: "; 
    cin >> n; 
  
    vector<vector<int>> adj(n, vector<int>(n)); 
    cout << "Enter adjacency matrix:\n"; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> adj[i][j]; 
  
    cout << "Enter starting vertex: "; 
    cin >> start; 
  
    vector<int> visited(n, 0); 
    bfs(start, adj, visited); 
  
    fill(visited.begin(), visited.end(), 0); 
    cout << "DFS Traversal: "; 
    dfs(start, adj, visited); 
    cout << "\n"; 
}
