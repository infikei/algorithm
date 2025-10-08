// Solve 2025-10-08

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

int cnt[5];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    while (m-- > 0) {
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            cnt[v + 2]++;
        }

        // (-2, -2) -> (2, 2)
        int tmp = cnt[0] / 2 * 2;
        cnt[0] -= tmp;
        cnt[4] += tmp;

        // (-2, -1) -> 2
        if (cnt[0] >= 1 && cnt[1] >= 1) {
            cnt[0]--;
            cnt[1]--;
            cnt[4]++;
        }

        // (-1, -1) -> 1
        tmp = cnt[1] / 2 * 2;
        cnt[1] -= tmp;
        cnt[3] += tmp / 2;

        if (cnt[4] >= 1) {
            ll two_pow = 1;

            for (int i = 0; i < cnt[4]; i++) {
                two_pow <<= 1;
            }

            cout << two_pow << '\n';
        }
        else if (cnt[3] >= 1) {
            cout << 1 << '\n';
        }
        else if (cnt[2] >= 1) {
            cout << 0 << '\n';
        }
        else if (cnt[1] >= 1) {
            cout << -1 << '\n';
        }
        else if (cnt[0] >= 1) {
            cout << -2 << '\n';
        }
    }

    return 0;
}
