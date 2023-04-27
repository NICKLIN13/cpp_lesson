#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r; // number of airports in Alan's country, ROC, and number of flight routes respectively
vector<vector<int>> dp; // dp[i][j] represents the maximum number of flights that can be arranged such that the last flight to take off from Alan's country is from airport i, and the last flight to take off from ROC is from airport j.

int solve() {
    // initialize base case
    dp[0][0] = 0;

    // fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (i > 0 && j > 0 && i != j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }

    // return answer
    return dp[n][m];
}

int main() {
    // input n, m, and r
    cin >> n >> m >> r;
    dp.resize(n+1, vector<int>(m+1, 0));

    // input flight routes
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
    }

    // solve and output answer
    cout << solve() << endl;
    return 0;
}
