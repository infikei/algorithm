// Solve 2025-11-16

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

int n, m, nm;
int board[4][4];
int mx = 0;

void recur(int idx, int selected, int score) {
    while (idx < nm && selected & (1 << idx)) {
        idx++;
    }

    if (idx == nm) {
        mx = max(mx, score);
        return;
    }

    int x = idx / m;
    int y = idx % m;
    recur(idx + 1, selected | (1 << idx), score + board[x][y]);

    int nx = x + 1;
    int ny = y;
    int n_idx = nx * m + ny;
    int n_selected = selected | (1 << idx);
    int num = board[x][y];

    while (nx < n && (selected & (1 << n_idx)) == 0) {
        n_selected |= (1 << n_idx);
        num = num * 10 + board[nx][ny];
        recur(idx + 1, n_selected, score + num);
        nx++;
        n_idx = nx * m + ny;
    }

    nx = x;
    ny = y + 1;
    n_idx = nx * m + ny;
    n_selected = selected | (1 << idx);
    num = board[x][y];

    while (ny < m && (selected & (1 << n_idx)) == 0) {
        n_selected |= (1 << n_idx);
        num = num * 10 + board[nx][ny];
        recur(n_idx + 1, n_selected, score + num);
        ny++;
        n_idx = nx * m + ny;
    }
}

int main() {
    FASTIO;

    cin >> n >> m;
    nm = n * m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            char c;
            cin >> c;
            board[x][y] = c - '0';
        }
    }

    recur(0, 0, 0);
    cout << mx << '\n';
    return 0;
}
