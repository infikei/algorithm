// Solve 2025-02-18

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

int n, l;
int board[100][100];

bool check_row(int x) {
    bool slope[100] = { false };

    for (int y = 1; y < n; y++) {
        if (board[x][y - 1] < board[x][y]) {
            if (board[x][y - 1] + 1 != board[x][y]) {
                return false;
            }

            int low = board[x][y - 1];

            for (int ny = y - l; ny < y; ny++) {
                if (ny < 0 || board[x][ny] != low || slope[ny]) {
                    return false;
                }

                slope[ny] = true;
            }
        }
        else if (board[x][y - 1] > board[x][y]) {
            if (board[x][y - 1] != board[x][y] + 1) {
                return false;
            }

            int low = board[x][y];

            for (int ny = y; ny < y + l; ny++) {
                if (ny >= n || board[x][ny] != low || slope[ny]) {
                    return false;
                }

                slope[ny] = true;
            }
        }
    }

    return true;
}

bool check_col(int y) {
    bool slope[100] = { false };

    for (int x = 1; x < n; x++) {
        if (board[x - 1][y] < board[x][y]) {
            if (board[x - 1][y] + 1 != board[x][y]) {
                return false;
            }

            int low = board[x - 1][y];

            for (int nx = x - l; nx < x; nx++) {
                if (nx < 0 || board[nx][y] != low || slope[nx]) {
                    return false;
                }

                slope[nx] = true;
            }
        }
        else if (board[x - 1][y] > board[x][y]) {
            if (board[x - 1][y] != board[x][y] + 1) {
                return false;
            }

            int low = board[x][y];

            for (int nx = x; nx < x + l; nx++) {
                if (nx >= n || board[nx][y] != low || slope[nx]) {
                    return false;
                }

                slope[nx] = true;
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    cin >> n >> l;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        if (check_row(x)) {
            cnt++;
        }
    }

    for (int y = 0; y < n; y++) {
        if (check_col(y)) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
