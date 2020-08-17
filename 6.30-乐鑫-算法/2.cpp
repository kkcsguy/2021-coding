#include "bits/stdc++.h"

using namespace std;

int f(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int dp[n + 2][n + 2];
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << f(nums) << endl;
    return 0;
}