// Solve 2023-03-11

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int p[200000];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    ll k;
    cin >> k;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p_i = p[i];
        ll tmp = k / p_i;
        while (tmp > 0) {
            ans += tmp;
            tmp /= p_i;
        }
    }
    cout << ans << '\n';

    return 0;
}