#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
vector<ll> dp;
int cur;
vector<vector<ll>> nums;

void generate_dp(int n) {
    dp.resize(n * n, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n * n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

void generate_array(int x, int y) {
    if (x == y) {
        nums[x][x] = dp[--cur];
        return;
    }
    for (int i = x; i < y; i++)
        nums[x][i] = dp[--cur];
    for (int i = x; i < y; i++)
        nums[i][y] = dp[--cur];
    for (int i = y; i > x; i--)
        nums[y][i] = dp[--cur];
    for (int i = y; i > x; i--)
        nums[i][x] = dp[--cur];
}

void print_array(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
}

void f(int n) {
    if (n == 0) return;
    int x = 0, y = n - 1;
    cur = n * n;
    nums.resize(n, vector<ll>(n, 0));
    while (x <= y) generate_array(x++, y--);
    print_array(n);
}

int main() {
    int n;
    cin >> n;
    generate_dp(n);
    f(n);
    return 0;
}