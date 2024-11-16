// Solve 2024-11-09

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

string zoac = "ZOAC";
int n, m;
char board[2001][2001];
int memo[2001][2001];
int row_memo[2001];
int col_memo[2001];

void init_memo() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            memo[x][y] = 0;
        }
    }
}

void init_row_memo_and_col_memo() {
    for (int x = 1; x <= n; x++) {
        row_memo[x] = 0;
    }

    for (int y = 1; y <= m; y++) {
        col_memo[y] = 0;
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    for (char z : zoac) {
        init_row_memo_and_col_memo();
        init_memo();

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                memo[x][y] = max(memo[x][y - 1], memo[x - 1][y]);

                if (board[x][y] == z) {
                    memo[x][y]++;
                }

                row_memo[x] = max(row_memo[x], memo[x][y]);
                col_memo[y] = max(col_memo[y], memo[x][y]);
            }
        }

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                memo[x][y] = max(max(row_memo[x - 1], col_memo[y - 1]), max(memo[x][y - 1], memo[x - 1][y]));

                if (board[x][y] == z) {
                    memo[x][y]++;
                }
            }
        }

        printw(memo[n][m]);
    }

    cout << '\n';

    return 0;
}
