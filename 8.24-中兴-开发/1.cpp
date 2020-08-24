#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0, cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}