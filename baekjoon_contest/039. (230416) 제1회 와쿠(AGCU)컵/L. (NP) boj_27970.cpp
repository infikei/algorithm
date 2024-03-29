// Solve 2023-04-18

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

    string s;
    cin >> s;

    const ll MOD = 1000000007;
    ll ans = 0;

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        ans <<= 1;
        if (*it == 'O') {
            ans++;
        }
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
