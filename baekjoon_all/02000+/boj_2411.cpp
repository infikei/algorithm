// Solve 2025-06-30

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

int n, m, a, b;
ll board[101][101];
vector<pii> items;

void dp(int x0, int y0, int x1, int y1) {
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            if (board[x][y] == -1) continue;

            if (x > x0 && board[x - 1][y] != -1) {
                board[x][y] += board[x - 1][y];
            }

            if (y > y0 && board[x][y - 1] != -1) {
                board[x][y] += board[x][y - 1];
            }
        }
    }
}

void input() {
    cin >> n >> m >> a >> b;

    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        items.emplace_back(x, y);
    }

    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1;
    }
}

ll pro() {
    items.emplace_back(1, 1);
    items.emplace_back(n, m);
    sort(items.begin(), items.end());

    for (int i = 0; i < size(items); i++) {
        if (board[items[i].first][items[i].second] == -1) {
            return 0;
        }
    }

    for (int i = 1; i < size(items); i++) {
        if (items[i - 1].second > items[i].second) {
            return 0;
        }
    }

    board[1][1] = 1;

    for (int i = 1; i < size(items); i++) {
        dp(items[i - 1].first, items[i - 1].second, items[i].first, items[i].second);
    }

    return board[n][m];
}

int main() {
    FASTIO;

    input();
    cout << pro() << '\n';
    return 0;
}
