// Solve 2026-04-07

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
const int CENTER = 1000003;

ll prefix_x[CENTER * 2 + 1];
ll prefix_y[CENTER * 2 + 1];
int dx[128];
int dy[128];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        x += CENTER;
        y += CENTER;

        prefix_x[0] += x;
        prefix_x[1]--;
        prefix_x[x + 1] += 2;

        prefix_y[0] += y;
        prefix_y[1]--;
        prefix_y[y + 1] += 2;
    }

    for (int i = 2; i <= CENTER * 2; i++) {
        prefix_x[i] += prefix_x[i - 1];
        prefix_x[i - 1] += prefix_x[i - 2];
        prefix_y[i] += prefix_y[i - 1];
        prefix_y[i - 1] += prefix_y[i - 2];
    }

    dx['S'] = 0;
    dy['S'] = 1;

    dx['J'] = 0;
    dy['J'] = -1;

    dx['I'] = 1;
    dy['I'] = 0;

    dx['Z'] = -1;
    dy['Z'] = 0;

    string cmds;
    cin >> cmds;
    int sx = CENTER;
    int sy = CENTER;

    for (char c : cmds) {
        sx += dx[c];
        sy += dy[c];
        cout << prefix_x[sx] + prefix_y[sy] << '\n';
    }

    return 0;
}
