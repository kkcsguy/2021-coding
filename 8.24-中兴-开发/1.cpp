#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int vec[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        ans = max(ans, vec[i]);
    }
    cout << ans << endl;
    return 0;
}