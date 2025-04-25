// Solve 2025-04-23

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int board[2000][2000];
int board2[2000][2000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    char ch;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> ch;
            board[x][y] = (ch == 'W' ? 0 : 1);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int a = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    a = 1 - a;
                }
            }

            board2[x][y] = a;
        }
    }

    cout << 1 << '\n';

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cout << (board[x][y] == board2[x][y] ? 2 : 3);
        }

        cout << '\n';
    }

    return 0;
}
