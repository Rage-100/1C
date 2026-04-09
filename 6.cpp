#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
int knapsack(int W, vector<int>& wt, vector<int>& val) { 
    int n = wt.size(); 
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); 
  
    for (int i = 1; i <= n; i++) { 
        for (int w = 0; w <= W; w++) { 
            if (wt[i-1] <= w) 
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]); 
            else 
                dp[i][w] = dp[i-1][w]; 
        } 
    } 
    return dp[n][W]; 
} 
  
int main() { 
    vector<int> values = {60, 100, 120}; 
    vector<int> weights = {10, 20, 30}; 
    int W = 50; 
    cout << "Maximum value: " << knapsack(W, weights, values) << endl; 
    return 0; 
} 
