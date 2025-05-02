// Solve 2025-05-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int c, v, l;
        cin >> c >> v >> l;

        ll memo[2] = { c, v };
        ll nmemo[2];

        for (int i = 2; i <= l; i++) {
            nmemo[0] = memo[1] * c % MOD; // 모음 -> 자음
            nmemo[1] = (memo[0] + memo[1]) * v % MOD; // (자음 | 모음) -> 모음

            swap(memo, nmemo);
        }

        cout << "Case #" << ti << ": " << memo[1] << '\n';
    }

    return 0;
}
