// Solve 2022-09-07
// Update 2025-12-26

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

ll x[4];
ll y[4];
ll len_square[6];

ll get_dist_square(int i, int j) {
    ll dx = x[i] - x[j];
    ll dy = y[i] - y[j];
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 0, u = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                len_square[u] = get_dist_square(i, j);
                u++;
            }
        }

        sort(len_square, len_square + 6);
        cout << (len_square[0] == len_square[3] && len_square[4] == len_square[5]) << '\n';
    }

    return 0;
}
