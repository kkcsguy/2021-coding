#include "bits/stdc++.h"

using namespace std;


pair<bool, int> f(vector<int> &bills) {
    int five = 0, ten = 0;
    for (int i = 0; i < bills.size(); i++) {
        int cur = bills[i];
        if (cur == 5) five++;
        else if(cur == 10) ten++;
        else if(cur != 20) return {false, i + 1};
        
        if (cur == 10) {
            if (five-- <= 0) {
                return {false, i + 1};
            }
        } else if (cur == 20) {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            } else if (five >= 2) {
                five -= 3;
            } else {
                return {false, i + 1};
            }
        }
    }
    return {true, bills.size()};
}

int main() {
    string s;
    cin >> s;
    s += ',';
    stringstream ss(s);

    vector<int> bills;
    char c[20];

    while (ss.get(c, 20, ',')) {
        bills.push_back(atoi(c));
        ss.get();
    }

    auto ans = f(bills);
//    cout.setf(ios_base::boolalpha);
    cout << ans.first << ',' << ans.second << endl;
    return 0;
}