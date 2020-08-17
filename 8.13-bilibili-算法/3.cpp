#include "bits/stdc++.h"

using namespace std;

int f(int n, int m, vector<int> times, vector<int> scores, vector<int> res) {
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= times[i]; --j) {
            res[j] = max(res[j - times[i]] + scores[i], res[j]);
        }
    }
    return res[m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> scores(n + 1, 0);
    vector<int> times(n + 1, 0);
    vector<int> res(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> times[i] >> scores[i];
    }
    cout << f(n, m, times, scores, res) << endl;
    return 0;
}