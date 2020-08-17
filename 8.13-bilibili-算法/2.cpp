#include "bits/stdc++.h"

using namespace std;


bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void getPrimes(vector<int> &primes, int m) {
    for (int i = 2; i <= m; i++) {
        if (isPrime(i))
            primes.push_back(i);
    }
}

int f(vector<int> primes, int n) {
    int ans = 0, sum = 0;
    int left = 0, right = 0;
    while (right < primes.size()) {
        if (sum < n) {
            sum += primes[right];
            right++;
        } else if (sum > n) {
            sum -= primes[left];
            left++;
        } else {
            sum -= primes[left++];
            sum += primes[right++];
            ans++;
        }
    }
    while (left < primes.size()) {
        if (sum == n) {
            ans++;
        }
        sum -= primes[left++];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    getPrimes(primes, n);
    cout << f(primes, n) << endl;
    return 0;
}