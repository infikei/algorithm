// Solve 2023-03-04

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

void sieve_of_eratosthenes(int k, vector<int> &res) {
    vector<bool> check(k + 1, true);
    for (int i = 2; i <= k; i++) {
        if (check[i]) {
            res.push_back(i);
            for (int j = (i << 1); j <= k; j += i) {
                check[j] = false;
            }
        }
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> primes(1, 1);
    sieve_of_eratosthenes(n, primes);

    int low = 0, high = SIZE(primes) - 1;
    while (low + 1 < high) {
        int mid = ((low + high) >> 1);
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