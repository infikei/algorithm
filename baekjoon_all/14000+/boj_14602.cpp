// Solve 2025-05-11

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

int board[30][30];
int nboard[30][30];

int main() {
    FASTIO;

    int m, n, k, w;
    cin >> m >> n >> k >> w;

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    for (int x = 0; x < m - w + 1; x++) {
        for (int y = 0; y < n - w + 1; y++) {
            vector<int> tmp;

            for (int i = 0; i < w; i++) {
                for (int j = 0; j < w; j++) {
                    tmp.push_back(board[x + i][y + j]);
                }
            }

            sort(tmp.begin(), tmp.end());
            nboard[x][y] = tmp[tmp.size() / 2];
        }
    }

    for (int x = 0; x < m - w + 1; x++) {
        for (int y = 0; y < n - w + 1; y++) {
            cout << nboard[x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
