#include "bits/stdc++.h"

using namespace std;

int f(vector<vector<int>> nums, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for (int k = 1; k <= j; k++) {
                dp[i][j] = max(dp[i][j], nums[i - 1][k - 1] + dp[i - 1][j - k]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    cout << f(nums, m, n) << endl;
    return 0;
}