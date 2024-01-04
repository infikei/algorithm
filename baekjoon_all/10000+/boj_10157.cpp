// Solve 2024-01-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int c, r, k;
    cin >> c >> r >> k;

    int rc = r * c;

    if (k > rc) {
        cout << 0 << '\n';
    }
    else {
        int board[1001][1001] = { 0 };
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        int x = 1;
        int y = 1;
        int d = 0;

        for (int i = 1; i < k; i++) {
            board[x][y] = i;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || nx > c || ny < 1 || ny > r || board[nx][ny] != 0) {
                if (++d == 4) {
                    d = 0;
                }

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
