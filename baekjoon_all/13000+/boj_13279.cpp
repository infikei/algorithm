// Solve 2026-04-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 100003;

int a[30001];
ll memo[30001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = n; j >= 2; j--) {
            memo[j] = (memo[j] + memo[j - 1] * a[i]) % MOD;
        }

        memo[1] = (memo[1] + a[i]) % MOD;
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int k;
        cin >> k;
        cout << memo[k] << '\n';
    }

    return 0;
}
