// Solve 2025-11-15

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

int n, m, k;
int board[10][10];
vector<pii> selected;
int mx = -INF;

void recur(int x, int y, int score) {
    if (size(selected) == k) {
        mx = max(mx, score);
        return;
    }

    for (int nx = x; nx < n; nx++) {
        for (int ny = (nx > x ? 0 : y); ny < m; ny++) {
            bool flag = true;

            for (pii& p : selected) {
                if (abs(p.first - nx) + abs(p.second - ny) == 1) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                selected.emplace_back(nx, ny);
                recur(nx, ny + 1, score + board[nx][ny]);
                selected.pop_back();
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    recur(0, 0, 0);
    cout << mx << '\n';
    return 0;
}
