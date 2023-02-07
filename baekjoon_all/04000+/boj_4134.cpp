// Solve 2022-08-04
// Update 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

bool is_prime(uint k) {
    if (k <= 1) {
        return false;
    }

    double i_end = sqrt(k);
    for (uint i = 2; i <= i_end; i++) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        uint n;
        cin >> n;
        while (!is_prime(n)) {
            n++;
        }
        cout << n << '\n';
    }

    return 0;
}