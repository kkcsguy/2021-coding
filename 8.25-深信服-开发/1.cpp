#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll min_val = 1000000, ans = 0, cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        ans += cur;
        min_val = min(min_val, cur);
    }
    cout << ans - min_val * n << endl;
    return 0;
}