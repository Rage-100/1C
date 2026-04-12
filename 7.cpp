#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char X[] = "AGGTAB", Y[] = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = (i==0 || j==0) ? 0 :
                       (X[i-1]==Y[j-1] ? dp[i-1][j-1]+1
                                       : max(dp[i-1][j], dp[i][j-1]));

    cout << "Length of LCS is " << dp[m][n];
}
