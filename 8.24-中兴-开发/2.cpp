#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
unordered_map<char, int> um;

// 判断i^j为奇数还是偶数，i为奇数或者j==0时结果为奇数
bool mi(ll i, ll j) {
    return (i % 2 == 1) || j == 0;
}

// 判断cur进制是奇数还是偶数
bool f(string s, ll cur) {
    int n = s.size();
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        if ((um[s[n - j - 1]] % 2) && mi(cur, j)) {
            ans += 1;
        }
    }
    return ans % 2;
}


bool g(string s, ll l, ll r) {
    //判断前两个是奇数还是偶数
    bool a = f(s, l);
    bool b = f(s, l + 1);
    ll c = r - l + 1;

    if (!a && !b) { // 如果前两个为偶数，则后面都为偶数0000000
        return false;
    } else if (a && b) { //如果前两个为奇数，后面的都是奇数1111111，结果就看l到r中间数的个数
        return c % 2;
    } else if (a) { //如果l为奇数，l+1为偶数，则后面为1010101010...
        return c % 4 == 1 || c % 4 == 2;
    } else { //如果l为偶数，l+1为奇数，则后面为0101010101...
        return c % 4 == 2 || c % 4 == 3;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        um[i + '0'] = i;
    }
    for (int i = 0; i < 26; i++) {
        um[i + 'A'] = i + 10;
    }
    ll n, l, r;
    string s;
    cin >> n;
    while (n--) {
        cin >> s >> l >> r;
        cout << g(s, l, r) << endl;
    }
    return 0;
}