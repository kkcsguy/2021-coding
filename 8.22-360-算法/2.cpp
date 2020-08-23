#include "bits/stdc++.h"

using namespace std;


list<int> li1, li2;

void f2() {
    swap(li1, li2);
}

void f1() {
    li1.push_back(li1.front());
    li1.pop_front();
    f2();
}


int main() {
    int n, m, cur;
    cin >> n >> m;
    for (int i = 1; i <= n;) {
        li1.push_back(i++);
        li2.push_back(i++);
    }
    for (int i = 0; i < m; i++) {
        cin >> cur;
        cur == 1 ? f1() : f2();
    }

    for (auto i = li1.begin(), j = li2.begin(); i != li1.end(); i++, j++) {
        cout << *i << ' ';
        cout << *j << ' ';
    }
    return 0;
}