#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    int n, a, b;
    cin >> s >> n;
    vector<int> to{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (n--) {
        cin >> a >> b;
        for (auto &p:to) p = p == a ? b : p;
    }
    for (auto &i:s)
        i = to[i - '0'] + '0';
    cout << s << endl;
    return 0;
}