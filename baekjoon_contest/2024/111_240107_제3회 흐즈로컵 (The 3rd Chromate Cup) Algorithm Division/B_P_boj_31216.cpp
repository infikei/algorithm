// Solve 2024-01-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<bool> is_prime(320000, true);
    vector<int> primes;
    primes.push_back(0);

    for (int i = 2; i < 320000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);

            for (int j = i * 2; j < 320000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cout << primes[primes[n]] << '\n';
    }

    return 0;
}
