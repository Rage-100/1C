#include <bits/stdc++.h> 
using namespace std; 
  
const int INF = 1e9; 
  
// Distance matrix for 4 cities (example) 
int dist[4][4] = { 
    {0, 10, 15, 20}, 
    {10, 0, 35, 25}, 
    {15, 35, 0, 30}, 
    {20, 25, 30, 0} 
}; 
int n = 4; 
  
// -------- Brute-force Optimal TSP -------- 
int tspOptimal() { 
    vector<int> cities; 
    for (int i = 1; i < n; i++) cities.push_back(i); 
    int bestCost = INF; 
  
    do { 
        int cost = dist[0][cities[0]]; 
        for (int i = 0; i < n - 2; i++) 
            cost += dist[cities[i]][cities[i+1]]; 
        cost += dist[cities[n-2]][0]; // return to start 
        bestCost = min(bestCost, cost); 
    } while (next_permutation(cities.begin(), cities.end())); 
  
    return bestCost; 
} 
  
// -------- Nearest Neighbor Approximation -------- 
int tspApprox() { 
    vector<bool> visited(n, false); 
    int cost = 0, curr = 0; 
    visited[curr] = true; 
  
    for (int step = 1; step < n; step++) { 
        int nextCity = -1, minDist = INF; 
        for (int j = 0; j < n; j++) { 
            if (!visited[j] && dist[curr][j] < minDist) { 
                minDist = dist[curr][j]; 
                nextCity = j; 
            } 
        } 
        cost += minDist; 
        curr = nextCity; 
        visited[curr] = true; 
    } 
    cost += dist[curr][0]; // return to start 
    return cost; 
} 
  
int main() { 
    int optimal = tspOptimal(); 
    int approx = tspApprox(); 
    double error = 100.0 * (approx - optimal) / optimal; 
  
    cout << "Optimal TSP cost: " << optimal << "\n"; 
    cout << "Approximation cost: " << approx << "\n"; 
    cout << "Approximation error: " << error << "%\n"; 
    return 0; 
} 
