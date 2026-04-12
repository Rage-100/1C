#include <iostream>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int val[n], wt[n];
    cout << "Enter values (profits) of " << n << " items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights of " << n << " items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter capacity of Knapsack: ";
    cin >> W;

    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
            K[i][w] = (i == 0 || w == 0) ? 0 :
                      (wt[i - 1] <= w ? max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
                                      : K[i - 1][w]);

    cout << "\nDynamic Programming Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++)
            cout << K[i][w] << " ";
        cout << "\n";
    }

    cout << "\nMaximum value that can be put in the knapsack = " << K[n][W] << endl;
}
