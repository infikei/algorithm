// Solve 2025-02-27

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string board[10];
int dx[4] = { 0, 1, 1, 1 };
int dy[4] = { 1, 1, 0, -1 };

int main() {
    FASTIO;

    for (int x = 0; x < 10; x++) {
        cin >> board[x];
    }

    bool koosaga_can_win = false;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int d = 0; d < 4; d++) {
                int koosaga = 0;
                bool possible = true;

                for (int i = 0; i < 5; i++) {
                    int nx = x + dx[d] * i;
                    int ny = y + dy[d] * i;

                    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || board[nx][ny] == 'O') {
                        possible = false;
                        break;
                    }
                    else if (board[nx][ny] == 'X') {
                        koosaga++;
                    }
                }

                if (possible && koosaga == 4) {
                    koosaga_can_win = true;
                    break;
                }
            }

            if (koosaga_can_win) break;
        }

        if (koosaga_can_win) break;
    }

    cout << (koosaga_can_win ? 1 : 0) << '\n';

    return 0;
}
