#include <iostream>
using namespace std;

#define N 4
#define INF 9999

int cost[N][N] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

int dp[1<<N][N], visitedAll = (1<<N)-1;

// Exact TSP (DP + Bitmask)
int tsp(int mask, int pos){
    if(mask == visitedAll) return cost[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for(int i=0;i<N;i++)
        if(!(mask & (1<<i)))
            ans = min(ans, cost[pos][i] + tsp(mask|1<<i, i));

    return dp[mask][pos] = ans;
}

// Nearest Neighbor Approximation
int approx(){
    bool vis[N]={0};
    int cur=0, total=0; vis[0]=1;

    cout << "\nNearest Neighbor Path: 0";
    for(int i=1;i<N;i++){
        int near=-1, mn=INF;
        for(int j=0;j<N;j++)
            if(!vis[j] && cost[cur][j]<mn && cost[cur][j])
                mn=cost[cur][j], near=j;

        vis[near]=1; total+=mn; cur=near;
        cout << " -> " << cur;
    }
    cout << " -> 0\n";
    return total + cost[cur][0];
}

int main(){
    for(int i=0;i<(1<<N);i++)
        for(int j=0;j<N;j++)
            dp[i][j] = -1;

    cout<<"Traveling Salesperson Problem (TSP) Comparison\n";
    cout<<"----------------------------------------------\n";

    int exact = tsp(1,0);
    int appr = approx();

    double err = (double)(appr - exact) / exact * 100;

    cout<<"\nOptimal (Exact) TSP Cost = "<<exact;
    cout<<"\nApproximate (Nearest Neighbor) TSP Cost = "<<appr;
    cout<<"\nApproximation Error = "<<err<<"%\n";
}
