// Solve 2025-09-08

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
vector<string> board;
string word;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int memo[100][100][79];

int dfs(int depth, int x, int y) {
    if (word[depth] != board[x][y]) {
        return 0;
    }

    if (depth == size(word) - 1) {
        return 1;
    }

    int& ret = memo[x][y][depth];

    if (ret != -1) {
        return ret;
    }

    ret = 0;

    for (int d = 0; d < 4; d++) {
        for (int i = 1; i <= k; i++) {
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                break;
            }

            ret += dfs(depth + 1, nx, ny);
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        string row;
        cin >> row;
        board.emplace_back(row);
    }

    cin >> word;
    memset(memo, -1, sizeof memo);
    int res = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            res += dfs(0, x, y);
        }
    }

    cout << res << '\n';
    return 0;
}
