#include "bits/stdc++.h"

using namespace std;

bool is_valid(string s) {
    if (s.size() > 10) return false;
    return all_of(s.begin(), s.end(), [](char i) {
        return (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z');
    });
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ans += is_valid(s);
    }
    cout << ans << endl;
    return 0;
}