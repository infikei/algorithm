// Solve 2025-01-26

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

int board[1000][1000];

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> board[x][y];
        }
    }

    if (r % 2 == 1) {
        string cmd;

        for (int i = c; i > 1; i--) cmd.push_back('R');
        cmd.push_back('D');
        for (int i = c; i > 1; i--) cmd.push_back('L');
        cmd.push_back('D');

        for (int i = r / 2; i > 0; i--) cout << cmd;
        for (int i = c; i > 1; i--) cout << 'R';
        cout << '\n';
    }
    else if (c % 2 == 1) {
        string cmd;

        for (int i = r; i > 1; i--) cmd.push_back('D');
        cmd.push_back('R');
        for (int i = r; i > 1; i--) cmd.push_back('U');
        cmd.push_back('R');

        for (int i = c / 2; i > 0; i--) cout << cmd;
        for (int i = r; i > 1; i--) cout << 'D';
        cout << '\n';
    }
    else {
        int min_val = board[0][1];
        int min_x = 0;
        int min_y = 1;

        for (int x = 0; x < r; x++) {
            for (int y = 1 - x % 2; y < c; y += 2) {
                if (board[x][y] < min_val) {
                    min_val = board[x][y];
                    min_x = x;
                    min_y = y;
                }
            }
        }

        string rrr;
        string lll;

        for (int y = c; y > 1; y--) {
            rrr.push_back('R');
            lll.push_back('L');
        }

        for (int x = 0; x < min_x / 2 * 2; x++) {
            if (x % 2 == 1) {
                cout << lll << 'D';
            }
            else {
                cout << rrr << 'D';
            }
        }

        string cur = "DR", nxt = "UR";

        for (int y = 0; y < c; y++) {
            if (y == min_y) {
                if (y < c - 1) {
                    cout << 'R';
                }
            }
            else {
                if (y == c - 1) {
                    cur.pop_back();
                }

                cout << cur;
                swap(cur, nxt);
            }
        }

        for (int x = min_x / 2 * 2 + 2; x < r; x++) {
            if (x % 2 == 1) {
                cout << 'D' << rrr;
            }
            else {
                cout << 'D' << lll;
            }
        }
    }

    return 0;
}
