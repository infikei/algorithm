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

bool is_prime(int k) {
    if (k < 2) {
        return false;
    }

    int i_end = sqrt(k);
    for (int i = 2; i <= i_end; i++) {
        if (k % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (is_prime(x)) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}