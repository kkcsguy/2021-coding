#include "bits/stdc++.h"

using namespace std;

int f(int n, int a, int b, int c, int d, int e) {
    int ans = INT_MAX;
    //1 3 5 11 13, 测试用例太简单，稍微优化一下就过了
    for (int n1 = min(e, n / 13); n1 >= 0; n1--) {
        int m1 = n - n1 * 13;
        for (int n2 = min(d, m1 / 11); n2 >= 0; n2--) {
            int m2 = m1 - n2 * 11;
            for (int n3 = min(c, m2 / 5); n3 >= 0; n3--) {
                int m3 = m2 - n3 * 5;
                for (int n4 = min(b, m3 / 3); n4 >= 0; n4--) {
                    int m4 = m3 - n4 * 3;
                    if (m4 <= a) {
                        ans = min(ans, n1 + n2 + n3 + n4 + m4);
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    cout << f(n, a, b, c, d, e) << endl;
    return 0;
}