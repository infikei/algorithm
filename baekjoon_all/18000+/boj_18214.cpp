// Solve 2025-10-02
// Update 2025-10-04

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
const int MOD = 1000000007;

int arr[5001];
int memo[5001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int max_v = 0;
    int last[2] = {0, 0};
    int cnt[2] = {0, 0};
    memo[0] = 1;

    for (int i = 1; i <= n; i++) {
        max_v = max(max_v, arr[i]);

        if (last[0] < arr[i]) {
            last[0] = arr[i];
            cnt[0]++;
        }
        else if (last[1] < arr[i]) {
            last[1] = arr[i];
            cnt[1]++;
        }
        else {
            cout << 0 << '\n';
            return 0;
        }

        if (max_v == i) {
            for (int v = max_v; v >= 0; v--) {
                int m0 = v >= cnt[0] ? memo[v - cnt[0]] : 0;
                int m1 = v >= cnt[1] ? memo[v - cnt[1]] : 0;
                memo[v] = (m0 + m1) % MOD;
            }

            cnt[0] = cnt[1] = 0;
        }
    }

    ll ans = 0;

    for (int i = n - m; i <= m; i++) {
        ans += memo[i];
    }

    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
