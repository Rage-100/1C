#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#define INF 9999
#define MAX 100

struct Edge {
    int u, v, w;
};

// --- UNION-FIND (Kruskal) ---
int find(vector<int>& parent, int i) {
    return (parent[i] == i) ? i : parent[i] = find(parent, parent[i]);
}

// --- PRIM'S ALGORITHM ---
void primMST(int cost[MAX][MAX], int n) {
    int selected[MAX] = {0}, no_edge = 0, totalCost = 0;
    selected = 1;
    cout << "\nPrim’s Algorithm Edges:\n";
    
    while (no_edge < n - 1) {
        int minW = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if (selected[i])
                for (int j = 0; j < n; j++)
                    if (!selected[j] && cost[i][j] < minW) {
                        minW = cost[i][j]; x = i; y = j;
                    }
        cout << "Edge " << ++no_edge << ": (" << x << " - " << y << ") cost: " << minW << endl;
        totalCost += minW;
        selected[y] = 1;
    }
    cout << "Total cost using Prim’s Algorithm = " << totalCost << endl;
}

// --- KRUSKAL'S ALGORITHM ---
void kruskalMST(int cost[MAX][MAX], int n) {
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (cost[i][j] != INF) edges.push_back({i, j, cost[i][j]});

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int totalCost = 0, edgeAdded = 0;
    cout << "\nKruskal’s Algorithm Edges:\n";
    for (auto &e : edges) {
        int uR = find(parent, e.u), vR = find(parent, e.v);
        if (uR != vR) {
            cout << "Edge " << ++edgeAdded << ": (" << e.u << " - " << e.v << ") cost: " << e.w << endl;
            totalCost += e.w;
            parent[uR] = vR;
            if (edgeAdded == n - 1) break;
        }
    }
    cout << "Total cost using Kruskal’s Algorithm = " << totalCost << endl;
}

int main() {
    int n, cost[MAX][MAX];
    cout << "Enter number of vertices: "; cin >> n;
    cout << "Enter the cost adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0 && i != j) cost[i][j] = INF;
        }

    clock_t start = clock();
    primMST(cost, n);
    double pT = double(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    kruskalMST(cost, n);
    double kT = double(clock() - start) / CLOCKS_PER_SEC;

    printf("\n⏱️ Execution Time Comparison:\nPrim’s Algorithm Time: %.10f seconds\nKruskal’s Algorithm Time: %.10f seconds\n", pT, kT);
    return 0;
}
