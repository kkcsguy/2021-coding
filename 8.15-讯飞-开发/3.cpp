#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    cout << bitset<32>(N).count() << endl;
    return 0;
}