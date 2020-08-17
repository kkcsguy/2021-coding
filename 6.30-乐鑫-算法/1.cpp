#include "bits/stdc++.h"

using namespace std;

int mi(int n) {
    if (n == 0) return 1;
    int ans = mi(n / 2);
    ans *= ans;
    if (n & 1) ans *= 3;
    return ans;
}

int f(int n) {
    if (n <= 4) return n;
    if (n % 3 == 1) return mi(n / 3 - 1) * 4;
    if (n % 3 == 2) return mi(n / 3) * 2;
    if (n % 3 == 0) return mi(n / 3);
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}