// Solve 2026-06-14

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
int board[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    int ret = 0;
    queue<pii> que;

    board[x][y] = 0;
    que.emplace(x, y);
    ret++;

    while (!que.empty()) {
        auto [cx, cy] = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 1) {
                board[nx][ny] = 0;
                que.emplace(nx, ny);
                ret++;
            }
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        string s;
        cin >> s;

        for (int y = 0; y < n; y++) {
            if (s[y] == '1') {
                board[x][y] = 1;
            }
        }
    }

    vector<int> vec;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == 1) {
                vec.push_back(bfs(x, y));
            }
        }
    }

    sort(vec.begin(), vec.end());
    cout << size(vec) << '\n';

    for (int a : vec) {
        cout << a << '\n';
    }

    return 0;
}
