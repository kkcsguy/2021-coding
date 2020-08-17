#include "bits/stdc++.h"

using namespace std;

int f(vector<vector<int>> nums, int n, int d) {
    int max_num = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_num = max(max_num, nums[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if((max_num - nums[i][j]) % d == 0)
                ans += (max_num - nums[i][j]) / d;
            else
                return -1;
        }
    }

    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    cout << f(nums, n, d) << endl;
    return 0;
}