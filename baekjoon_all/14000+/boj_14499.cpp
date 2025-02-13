// Solve 2025-02-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int dice[6];
int board[20][20];

int main() {
    FASTIO;

    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (k-- > 0) {
        int d;
        cin >> d;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (d == 1) {
            swap(dice[3], dice[2]);
            swap(dice[2], dice[1]);
            swap(dice[1], dice[0]);
        }
        else if (d == 2) {
            swap(dice[0], dice[1]);
            swap(dice[1], dice[2]);
            swap(dice[2], dice[3]);
        }
        else if (d == 3) {
            swap(dice[4], dice[0]);
            swap(dice[0], dice[5]);
            swap(dice[5], dice[2]);
        }
        else if (d == 4) {
            swap(dice[2], dice[5]);
            swap(dice[5], dice[0]);
            swap(dice[0], dice[4]);
        }

        if (board[nx][ny] == 0) {
            board[nx][ny] = dice[2];
        }
        else {
            dice[2] = board[nx][ny];
            board[nx][ny] = 0;
        }

        x = nx;
        y = ny;

        println(dice[0]);
    }

    return 0;
}
