// Solve 2026-08-30

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

void draw_rectangle(int xs, int xe, int ys, int ye, vector<string>& board) {
    board[xs][ys] = '+';
    board[xs][ye] = '+';
    board[xe][ys] = '+';
    board[xe][ye] = '+';

    for (int y = ys + 1; y < ye; y++) {
        board[xs][y] = '-';
        board[xe][y] = '-';
    }

    for (int x = xs + 1; x < xe; x++) {
        board[x][ys] = 'I';
        board[x][ye] = 'I';

        for (int y = ys + 1; y < ye; y += 2) {
            board[x][y] = '-';
        }

        for (int y = ys + 2; y < ye; y += 2) {
            board[x][y] = 'X';
        }
    }
}

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    int h = max(m, n) + 2;
    int w = (m + n) * 2 + 16;
    vector<string> board(h, string(w, ' '));

    draw_rectangle(0, m + 1, 0, m * 2 + 2, board);
    draw_rectangle(0, n + 1, m * 2 + 13, m * 2 + n * 2 + 15, board);

    for (string& row : board) {
        cout << row << '\n';
    }

    return 0;
}
