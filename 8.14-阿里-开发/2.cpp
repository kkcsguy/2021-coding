#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int f(string s) {
    int sum = 0;
    int n = s.size();
    for (auto i:s) {
        sum += i - '0';
    }
    ll dp[n][sum + 1];
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= sum; j++) {
        dp[0][j] = j <= 9 ? 1 : 0;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j - k >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    return dp[n - 1][sum] - 1;
}

int main() {
    int q;
    cin >> q;
    string s;
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << f(s) << endl;
    }
    return 0;
}