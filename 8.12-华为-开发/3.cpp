#include "bits/stdc++.h"

using namespace std;

/* 
    012345678901234567,7
    0     1
     2   3
      4 5
       6
      7 8
     9   0
    1     2
     3   4
      5 6
       7  
*/


string f(string s, int n) {
    string ans;
    int sz = s.size();
    int bs = 2 * n - 3;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            for (int j = 0; j <= sz / bs; j++) {
                if (j * bs + 2 * i < sz)
                    ans += s[j * bs + 2 * i];
                if (i != 0 && j * bs + bs - 2 * i < sz)
                    ans += s[j * bs + bs - 2 * i];
            }
        } else if (i == n / 2) {
            for (int j = 0; j <= sz / bs; j++) {
                if (j * bs + n - 1 < sz)
                    ans += s[j * bs + n - 1];
            }
        } else {
            for (int j = 0; j <= sz / bs; j++) {
                if (j * bs + 2 * (n - 1 - i) + 1 < sz)
                    ans += s[j * bs + 2 * (n - 1 - i) + 1];
                if (i != n - 1 && j * bs + bs - 2 * (n - 1 - i) + 1 < sz)
                    ans += s[j * bs + bs - 2 * (n - 1 - i) + 1];
            }
        }
    }
    return ans;
}

int main() {
    string s;
    int n;
    getline(cin, s, ',');
    cin >> n;
    cout << f(s, n) << endl;
    return 0;
}