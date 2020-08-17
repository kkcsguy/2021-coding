#include "bits/stdc++.h"

using namespace std;

int f(int n) {
    int a = n;
    int b = 0;
    while (n) {
        b += n % 10;
        n /= 10;
    }
    return a % b;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}