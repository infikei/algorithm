// Solve 2026-02-02

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
int b[10001];
int days[101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        cin >> a[u];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int u = 1; u <= n; u++) {
            days[u]++;
        }

        int v = b[i];

        if (days[v] <= a[v] || b[i - 1] == b[i]) {
            days[v] = 0;
        }
    }

    int cnt = 0;

    for (int u = 1; u <= n; u++) {
        days[u]++;

        if (days[u] > a[u]) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
