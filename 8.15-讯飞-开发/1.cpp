#include "bits/stdc++.h"

using namespace std;

typedef long long ll; // 通常情况看到大数，就使用long long

//不得不说讯飞的笔试题还是挺简单的，四个for循环o(n4)居然都过了

ll f(vector<vector<ll>> nums, int n, int m) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll max_num = 0;
            for (int a = 0; a < n; a++) {
                if (a == i) continue;
                for (int b = 0; b < m; b++) {
                    if (b == j) continue;
                    max_num = max(max_num, nums[a][b]);
                }
            }
            ans = max(ans, nums[i][j] * max_num);
        }
    }
    return ans;
}


// o(n2)的解法

ll f2(vector<vector<ll>> nums, int n, int m) {
    ll ans = 0;
    vector<array<ll, 2>> max_nums(n, array<ll, 2>());
    vector<array<ll, 2>> second_max_nums(n, array<ll, 2>());
    //预存每一行的最大值和次大值及位置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums[i][j] >= max_nums[i][0]) {
                second_max_nums[i] = max_nums[i];
                max_nums[i] = {nums[i][j], j};
            } else if (nums[i][j] >= second_max_nums[i][0]) {
                second_max_nums[i] = {nums[i][j], j};
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (max_nums[i][1] == max_nums[j][1]) {
                ans = max(ans, max(max_nums[i][0] * second_max_nums[j][0], max_nums[j][0] * second_max_nums[i][0]));
            } else {
                ans = max(ans, max_nums[i][0] * max_nums[j][0]);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> vec(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    cout << f2(vec, n, m) << endl;
    return 0;
}