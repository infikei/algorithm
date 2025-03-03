// Solve 2022-10-17
// Update 2025-03-03

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

const int MOD = 10007;

int memo[10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        memo[i] = 1;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 9; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                memo[i] += memo[j];
            }

            memo[i] %= MOD;
        }
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += memo[i];
    }

    ans %= MOD;

    cout << ans << '\n';

    return 0;
}
