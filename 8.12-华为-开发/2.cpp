#include "bits/stdc++.h"

using namespace std;

int s, m, n;
bool ans = false;

void dfs(vector<vector<int>> &nums, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || nums[i][j] != 1) return;
    if (i == m - 1 && j == n - 1) {
        ans = true;
        return;
    }
    nums[i][j] = 2;
    dfs(nums, i - s, j);
    dfs(nums, i + s, j);
    dfs(nums, i, j - s);
    dfs(nums, i, j + s);
}

int main() {
    cin >> s >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    dfs(nums, 0, 0);
    cout << ans;
    return 0;
}