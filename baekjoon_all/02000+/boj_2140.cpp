// Solve 2025-11-19

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
vector<string> board;

int solution() {
    if (n <= 2) {
        return 0;
    }

    if (n == 3) {
        return board[0][0] == '1';
    }

    int mx = (n - 4) * (n - 4);

    if (board[0][0] == '1') {
        board[1][1] = '*';
        mx++;
    }

    if (board[0][n - 1] == '1') {
        board[1][n - 2] = '*';
        mx++;
    }

    if (board[n - 1][0] == '1') {
        board[n - 2][1] = '*';
        mx++;
    }

    if (board[n - 1][n - 1] == '1') {
        board[n - 2][n - 2] = '*';
        mx++;
    }

    for (int x = 2; x <= n - 3; x++) {
        int cnt = (board[x - 2][1] == '*') + (board[x - 1][1] == '*');
        int val = board[x - 1][0] - '0';

        if (cnt < val) {
            board[x][1] = '*';
            mx++;
        }
    }

    for (int x = 2; x <= n - 3; x++) {
        int cnt = (board[x - 2][n - 2] == '*') + (board[x - 1][n - 2] == '*');
        int val = board[x - 1][n - 1] - '0';

        if (cnt < val) {
            board[x][n - 2] = '*';
            mx++;
        }
    }

    for (int y = 2; y <= n - 3; y++) {
        int cnt = (board[1][y - 2] == '*') + (board[1][y - 1] == '*');
        int val = board[0][y - 1] - '0';

        if (cnt < val) {
            board[1][y] = '*';
            mx++;
        }
    }

    for (int y = 2; y <= n - 3; y++) {
        int cnt = (board[n - 2][y - 2] == '*') + (board[n - 2][y - 1] == '*');
        int val = board[n - 1][y - 1] - '0';

        if (cnt < val) {
            board[n - 2][y] = '*';
            mx++;
        }
    }

    return mx;
}

int main() {
    FASTIO;

    cin >> n;
    board.assign(n, string());

    for (string& row : board) {
        cin >> row;
    }

    cout << solution() << '\n';
    return 0;
}
