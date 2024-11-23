// Solve 2024-11-22

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

int dx[4] = { -1, -1, 0, 0 };
int dy[4] = { -1, 0, -1, 0 };

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    vector<string> board(r);

    for (string &row : board) {
        cin >> row;
    }

    int ans[5] = { 0 };

    for (int x = 1; x < r; x++) {
        for (int y = 1; y < c; y++) {
            int building = 0;
            int car = 0;

            for (int d = 0; d < 4; d++) {
                char c = board[x + dx[d]][y + dy[d]];

                if (c == '#') {
                    building++;
                }
                else if (c == 'X') {
                    car++;
                }
            }

            if (building > 0) {
                continue;
            }

            ans[car]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        println(ans[i]);
    }

    return 0;
}
