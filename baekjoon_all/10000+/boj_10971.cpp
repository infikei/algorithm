// Solve 2026-01-04

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

int n;
int w[10][10];
int mn;

void recur(int cur, int selected, int dist) {
    if (selected == (1 << n) - 1) {
        if (w[cur][0] != 0) {
            mn = min(mn, dist + w[cur][0]);
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (selected & (1 << i)) continue;
        if (w[cur][i] == 0) continue;

        recur(i, selected | (1 << i), dist + w[cur][i]);
    }
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    mn = INF;
    recur(0, 1, 0);
    cout << mn << '\n';
    return 0;
}
