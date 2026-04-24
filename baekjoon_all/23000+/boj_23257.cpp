// Solve 2026-04-12

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

int a[101];
bool memo[101][1024];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    memo[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int v = 0; v < 1024; v++) {
                if (memo[j - 1][v]) {
                    memo[j][v ^ a[i]] = true;
                }
            }
        }
    }

    int mx = -1;

    for (int v = 1023; v >= 0; v--) {
        if (memo[m][v]) {
            mx = v;
            break;
        }
    }

    cout << mx << '\n';
    return 0;
}
