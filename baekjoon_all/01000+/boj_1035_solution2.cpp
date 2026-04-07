// Solve 2026-04-06

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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pii> blocks;
int n_blocks;
int board;
int mn_dist = INF;

bool is_connected() {
    int ix = -1;
    int iy = -1;

    for (int w = 0; w < 25; w++) {
        if (board & (1 << w)) {
            ix = w / 5;
            iy = w % 5;
            break;
        }
    }

    int visited = 0;
    queue<pii> que;
    visited |= (1 << (ix * 5 + iy));
    que.emplace(ix, iy);
    int connected_blocks = 1;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nw = nx * 5 + ny;

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited & (1 << nw)) continue;
            if ((board & (1 << nw)) == 0) continue;

            visited |= (1 << nw);
            que.emplace(nx, ny);
            connected_blocks++;
        }
    }

    return connected_blocks == n_blocks;
}

void recur(int depth, int dist) {
    if (depth == n_blocks) {
        if (is_connected()) {
            mn_dist = min(mn_dist, dist);
        }

        return;
    }

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            int w = x * 5 + y;

            if (board & (1 << w)) continue;

            board |= (1 << w);
            recur(depth + 1, dist + abs(blocks[depth].first - x) + abs(blocks[depth].second - y));
            board ^= (1 << w);
        }
    }
}

int main() {
    FASTIO;

    for (int x = 0; x < 5; x++) {
        string s;
        cin >> s;

        for (int y = 0; y < 5; y++) {
            if (s[y] == '*') {
                blocks.emplace_back(x, y);
                n_blocks++;
            }
        }
    }

    recur(0, 0);
    cout << mn_dist << '\n';
    return 0;
}
