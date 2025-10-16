// Solve 2025-10-14

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

struct CCTV{
    int x, y, type;

    CCTV(int x, int y, int type) : x(x), y(y), type(type) {
    }
};

int n, m;
int board[8][8];
vector<CCTV> cctv;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<vector<int>>> cctv_direction = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};
int mn;

int change(int x, int y, int d, int val, int new_val) {
    int ret = 0;
    x += dx[d];
    y += dy[d];

    while (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != 6) {
        if (board[x][y] == val) {
            board[x][y] = new_val;
            ret++;
        }

        x += dx[d];
        y += dy[d];
    }

    return ret;
}

void recur(int depth, int val) {
    if (depth == size(cctv)) {
        mn = min(mn, val);
        return;
    }

    CCTV& cur_cctv = cctv[depth];

    for (vector<int>& dir : cctv_direction[cur_cctv.type]) {
        for (int d : dir) {
            val -= change(cur_cctv.x, cur_cctv.y, d, 0, -(depth + 1));
        }

        recur(depth + 1, val);

        for (int d : dir) {
            val += change(cur_cctv.x, cur_cctv.y, d, -(depth + 1), 0);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;
    int val = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];

            if (board[x][y] == 0) {
                val++;
            }
            else if (board[x][y] != 6) {
                cctv.emplace_back(x, y, board[x][y]);
            }
        }
    }

    mn = val;
    recur(0, val);
    cout << mn << '\n';
    return 0;
}
