// Solve 2026-01-05

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
int x[16];
int y[16];
double w[16][16];
double memo[16][1 << 16];

double get_dist(int u, int v) {
    int dx = x[u] - x[v];
    int dy = y[u] - y[v];
    return sqrt(dx * dx + dy * dy);
}

double recur(int cur, int selected) {
    if (selected == (1 << n) - 1) {
        return (w[cur][0] == 0) ? INF : w[cur][0];
    }

    if (memo[cur][selected] != -1) {
        return memo[cur][selected];
    }

    double mn = INF;

    for (int i = 0; i < n; i++) {
        if (selected & (1 << i)) continue;
        if (w[cur][i] == 0) continue;

        double nxt_mn = recur(i, selected | (1 << i));

        if (nxt_mn != INF) {
            mn = min(mn, w[cur][i] + nxt_mn);
        }
    }

    memo[cur][selected] = mn;
    return mn;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            w[i][j] = get_dist(i, j);
            w[j][i] = w[i][j];
        }
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            memo[i][j] = -1;
        }
    }

    SETP(9);
    cout << recur(0, 1) << '\n';
    return 0;
}
