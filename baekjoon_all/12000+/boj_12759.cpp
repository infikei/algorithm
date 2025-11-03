// Solve 2025-10-31

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

int board[4][4];
int game[9][2];

int check_lines() {
    for (int x = 1; x <= 3; x++) {
        if (board[x][1] != 0 && board[x][1] == board[x][2] && board[x][1] == board[x][3]) {
            return board[x][1];
        }
    }

    for (int y = 1; y <= 3; y++) {
        if (board[1][y] != 0 && board[1][y] == board[2][y] && board[1][y] == board[3][y]) {
            return board[1][y];
        }
    }

    if (board[1][1] != 0 && board[1][1] == board[2][2] && board[1][1] == board[3][3]) {
        return board[1][1];
    }

    if (board[1][3] != 0 && board[1][3] == board[2][2] && board[1][3] == board[3][1]) {
        return board[1][3];
    }

    return 0;
}

int get_winner(int player) {
    for (int i = 0; i < 9; i++) {
        int x = game[i][0];
        int y = game[i][1];
        board[x][y] = player;
        int winner = check_lines();

        if (winner != 0) return winner;

        player = 3 - player;
    }

    return 0;
}

int main() {
    FASTIO;

    int player;
    cin >> player;

    for (int i = 0; i < 9; i++) {
        cin >> game[i][0] >> game[i][1];
    }

    cout << get_winner(player) << '\n';
    return 0;
}
