#include "bits/stdc++.h"

using namespace std;

int ans = 0, n;
const string CHINA = "CHINA";

void dfs(const vector<string>&strs, int i, int j, int cur = 0) {
    if (cur == 5) {
        ans++;
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (strs[i][j] == CHINA[cur]) {
        dfs(strs, i - 1, j, cur + 1);
        dfs(strs, i + 1, j, cur + 1);
        dfs(strs, i, j - 1, cur + 1);
        dfs(strs, i, j + 1, cur + 1);
    }
}

void f(const vector<string> &strs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strs[i][j] == 'C') {
                dfs(strs, i, j);
            }
        }
    }
}

int main() {
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) cin >> strs[i];
    f(strs);
    cout << ans / 4 << endl;
    return 0;
}
