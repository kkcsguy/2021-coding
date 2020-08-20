#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<char, int> um;
    for (auto i:s) um[i]++;
    for (auto i:um) pq.push(i.second);
    int n = pq.size();
    int sum = 0, a, b;
    for (int i = 2; i <= n; i++) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << sum << endl;
    return 0;
}