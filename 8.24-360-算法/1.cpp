#include "bits/stdc++.h"

using namespace std;

int main() {
    char c;
    cin.get(c);
    string ans;
    ans += c - 'a' + 'A';
    while (cin.get(c)) {
        if (c == '\n')
            break;
        if (c == 'n') {
            cout << ans << endl;
            ans = "N";
        } else {
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}