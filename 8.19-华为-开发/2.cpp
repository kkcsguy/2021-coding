#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define MAX_NODE_NUM 1024
ll c[MAX_NODE_NUM][MAX_NODE_NUM] = {0};
const ll mod = 1000000007;

void generate_c() {
    for (int i = 1; i < MAX_NODE_NUM; i++) {
        c[i][i] = 1;
        c[i][0] = 1;
        c[i][1] = i;
    }
    for (int i = 3; i < MAX_NODE_NUM; i++) {
        for (int j = 2; j < i; j++) {
//            c[i][j] = c[i][j - 1] * (i - j + 1) / j; // 这样会溢出, 而且模运算不能和除法一起，笔试30%没过
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j] ) % mod; //我太菜了，呜呜呜
        }
    }
//    cout<<c[1000][50]<<endl;
}

ll f(vector<int> &nums, int total) {
    ll ans = 1, curMaxNum = 1;
    for (auto &num : nums) {
        if (total == 0) break;
        if (num == 0 || curMaxNum < num) return 0;
        total -= num;
        ans *= c[curMaxNum][num];
        ans %= mod;
        curMaxNum = 2 * num;
    }
    return ans % mod;
}


int main() {
    int n, tmp;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp >= n) {
            cout << 0 << endl;
            return 0;
        }
        nums[tmp]++;
    }
    generate_c();
    cout << f(nums, n) << endl;
    return 0;
}