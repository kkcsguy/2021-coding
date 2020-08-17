#include "bits/stdc++.h"

using namespace std;

int f(int n) {
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1), v{1, 5, 10, 25};
    dp[0] = 1;
    for (int i : v) {
        for (int j = i; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}