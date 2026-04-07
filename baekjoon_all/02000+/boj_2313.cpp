// Solve 2026-03-29

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

int mx_sum[1001];
int mx_left[1001];
int mx_right[1001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        mx_sum[i] = -20000;
        int prefix_sum = 0;
        int prefix_start = 1;

        for (int j = 1; j <= m; j++) {
            int v;
            cin >> v;

            if (v >= prefix_sum + v) {
                prefix_sum = v;
                prefix_start = j;
            }
            else {
                prefix_sum = prefix_sum + v;
            }

            if (prefix_sum > mx_sum[i]) {
                mx_sum[i] = prefix_sum;
                mx_left[i] = prefix_start;
                mx_right[i] = j;
            }
            else if (prefix_sum == mx_sum[i] && (j - prefix_start) < (mx_right[i] - mx_left[i])) {
                mx_left[i] = prefix_start;
                mx_right[i] = j;
            }
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += mx_sum[i];
    }

    cout << ans << '\n';

    for (int i = 1; i <= n; i++) {
        cout << mx_left[i] << ' ' << mx_right[i] << '\n';
    }

    return 0;
}
