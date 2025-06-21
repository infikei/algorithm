// Solve 2025-06-20

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

int a[100001];
int p[110010];

int main() {
    FASTIO;

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int d = a[i] / m;
        int r = a[i] % m;

        p[i + 1] -= m;
        p[i + d + 1] += m - r;
        p[i + d + 2] += r;
    }

    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
        a[i] += a[i - 1] + p[i];
    }

    while (q-- > 0) {
        int cmd, t;
        cin >> cmd >> t;

        if (cmd == 1) {
            cout << a[t] << '\n';
        }
        else {
            cout << -p[t] << '\n';
        }
    }

    return 0;
}
