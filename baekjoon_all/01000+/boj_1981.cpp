// Solve 2025-10-10

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
int board[100][100];
vector<int> values;
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bfs(int l, int r) {
    if (board[0][0] < l || r < board[0][0]) {
        return false;
    }

    queue<pii> bfs_que;
    memset(visited, false, sizeof visited);
    visited[0][0] = true;
    bfs_que.emplace(0, 0);

    while (!bfs_que.empty()) {
        pii cur = bfs_que.front();
        bfs_que.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] || board[nx][ny] < l || board[nx][ny] > r) continue;

            if (nx == n - 1 && ny == n - 1) {
                return true;
            }

            visited[nx][ny] = true;
            bfs_que.emplace(nx, ny);
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
            values.push_back(board[x][y]);
        }
    }

    sort(ALL(values));
    UNIQUE(values);
    int min_val = values.back() - values[0];

    for (int i = 0; i < size(values); i++) {
        int left = i;
        int right = size(values) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (bfs(values[i], values[mid])) {
                min_val = min(min_val, values[mid] - values[i]);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }

    cout << min_val << '\n';
    return 0;
}
