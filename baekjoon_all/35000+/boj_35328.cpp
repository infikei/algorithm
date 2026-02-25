// Solve 2026-02-22

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

int n, k;
int board[501][501];
int part_sum[501][501];
int mx;

void update(int r, int c, int v) {
    int diff = v - board[r][c];
    board[r][c] = v;

    for (int x = max(k, r), xe = min(n, r + k - 1); x <= xe; x++) {
        for (int y = max(k, c), ye = min(n, c + k - 1); y <= ye; y++) {
            part_sum[x][y] += diff;
            mx = max(mx, part_sum[x][y]);
        }
    }
}

int main() {
    FASTIO;

    int q;
    cin >> n >> k >> q;

    while (q-- > 0) {
        int r, c, v;
        cin >> r >> c >> v;

        update(r, c, v);

        cout << mx << '\n';
    }

    return 0;
}
