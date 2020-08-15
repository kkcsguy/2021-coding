#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    getline(cin , s); // 字符串可能有空格
    int n;
    cin >> n;
    n = n % s.size();
    cout << s.substr(n) + s.substr(0, n) << endl;
    return 0;
}