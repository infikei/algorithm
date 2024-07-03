// Solve 2023-03-04
// Update 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void sieve_of_eratosthenes(int k, vector<int> &primes) {
    vector<bool> check(k + 1, false);
    for (int i = 2; i <= k; i++) {
        if (!check[i]) {
            primes.push_back(i);
            for (int ii = i + i; ii <= k; ii += i) {
                check[ii] = true;
            }
        }
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> primes(1, 0);

    sieve_of_eratosthenes(n, primes);

    int low = 0, high = SIZE(primes) - 1;

    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        int response;

        if (mid == 0) {
            response = 1;
        }
        else {
            cout << "? " << primes[mid] << endl;
            cin >> response;
        }

        if (response == 1) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << "! " << primes[high] << endl;

    return 0;
}
