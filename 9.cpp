#include <iostream> 
#include <vector> 
using namespace std; 
  
const int INF = 1e9; // Represents "infinity" 
  
// Floyd-Warshall function 
void floydWarshall(vector<vector<int>>& dist, int n) { 
    for (int k = 0; k < n; k++) {          // intermediate vertex 
        for (int i = 0; i < n; i++) {      // source vertex 
            for (int j = 0; j < n; j++) {  // destination vertex 
                if (dist[i][k] < INF && dist[k][j] < INF) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            } 
        } 
    } 
} 
  
int main() { 
    int n = 4; // number of vertices 
    vector<vector<int>> dist = { 
        {0,   5,  INF, 10}, 
        {INF, 0,   3, INF}, 
        {INF, INF, 0,   1}, 
        {INF, INF, INF, 0} 
    }; 
  
    floydWarshall(dist, n); 
  
    cout << "Shortest distance matrix:\n"; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (dist[i][j] == INF) cout << "INF "; 
            else cout << dist[i][j] << " "; 
        } 
        cout << "\n"; 
    } 
  
    return 0; 
}
