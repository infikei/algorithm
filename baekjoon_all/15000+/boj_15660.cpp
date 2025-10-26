// Solve 2025-10-26

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

struct Block{
    int sum;
    vector<int> pos;

    Block(int sum, vector<int>& vec) : sum(sum) {
        pos = vec;
    }

    bool operator<(const Block& rhs) const {
        return sum > rhs.sum;
    }
};

int board[504][504];
int dxdy[19][8] = {
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 1, -1, 1, 0},
    {0, 0, 0, 1, 1, 1, 1, 2},
    {0, 0, 1, 0, -1, 1, 0, 1},
    {0, 0, 1, 0, 1, 1, 2, 1},

    {0, 0, 0, 1, 0, 2, 0, 3},
    {0, 0, 0, 1, 0, 2, -1, 0},
    {0, 0, 0, 1, 0, 2, -1, 1},
    {0, 0, 0, 1, 0, 2, -1, 2},
    {0, 0, 0, 1, 0, 2, 1, 0},
    {0, 0, 0, 1, 0, 2, 1, 1},
    {0, 0, 0, 1, 0, 2, 1, 2},

    {0, 0, 1, 0, 2, 0, 3, 0},
    {0, 0, 1, 0, 2, 0, 0, -1},
    {0, 0, 1, 0, 2, 0, 1, -1},
    {0, 0, 1, 0, 2, 0, 2, -1},
    {0, 0, 1, 0, 2, 0, 0, 1},
    {0, 0, 1, 0, 2, 0, 1, 1},
    {0, 0, 1, 0, 2, 0, 2, 1}
};
bool selected[504][504];

void select(Block& block, bool state) {
    for (int i = 0; i < 8; i += 2) {
        selected[block.pos[i]][block.pos[i + 1]] = state;
    }
}

bool can_select(Block& block) {
    for (int i = 0; i < 8; i += 2) {
        if (selected[block.pos[i]][block.pos[i + 1]]) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    int mx = 0;
    priority_queue<Block> pq;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int d = 0; d < 19; d++) {
                vector<int> pos(8);
                int sum = 0;

                for (int i = 0; i < 8; i += 2) {
                    int nx = pos[i] = x + dxdy[d][i];
                    int ny = pos[i + 1] = y + dxdy[d][i + 1];
                    sum += board[nx][ny];
                }

                mx = max(mx, sum);
                pq.emplace(sum, pos);
            }

            while (size(pq) > 100) {
                pq.pop();
            }
        }
    }

    vector<Block> blocks;

    while (!pq.empty()) {
        blocks.push_back(pq.top());
        pq.pop();
    }

    int mx2 = 0;

    for (int i = size(blocks) - 1; i >= 0; i--) {
        select(blocks[i], true);

        for (int j = i - 1; j >= 0; j--) {
            if (blocks[i].sum + blocks[j].sum < mx2) break;

            if (can_select(blocks[j])) {
                mx2 = max(mx2, blocks[i].sum + blocks[j].sum);
            }
        }

        select(blocks[i], false);
    }

    cout << mx2 << '\n';
    return 0;
}
