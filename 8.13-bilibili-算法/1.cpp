// #include "bits/stdc++.h"

// using namespace std;

// bool f(string s1, string s2) {
//     if (s1.size() != s2.size())
//         return false;
//     unordered_map<char, int> um;
//     for (auto i:s1) {
//         um[i]++;
//     }
//     for (auto i:s2) {
//         if (--um[i] < 0)
//             return false;
//     }
//     return true;
// }

// int main() {
//     string s1, s2;
//     getline(cin, s1);
//     getline(cin, s2);
//     cout << f(s1, s2) << endl;
//     return 0;
// }


#include "bits/stdc++.h"

using namespace std;


int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << (s1 == s2) << endl;
    return 0;
}