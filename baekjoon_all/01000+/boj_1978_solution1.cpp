// Solve 2023-03-01

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

const int MAX_SIZE = 1001;

int main() {
    FASTIO;

    vector<bool> primes(MAX_SIZE, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (primes[i]) {
            for (int j = i + i; j < MAX_SIZE; j += i) {
                primes[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (primes[x]) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}