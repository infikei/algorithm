// Solve 2023-04-20

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

void get_primes(vector<int> &primes) {
    bool is_prime[104] = { false };

    for (int i = 2; i < 104; i++) {
        if (!is_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < 104; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

int main() {
    FASTIO;

    vector<int> primes;
    get_primes(primes);

    int n;
    cin >> n;

    for (int i = 1, i_end = SIZE(primes); i < i_end; i++) {
        int ans = primes[i - 1] * primes[i];
        if (n < ans) {
            cout << ans << '\n';
            break;
        }
    }

    return 0;
}
