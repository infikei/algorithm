// Solve 2025-04-17

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

int board[1001][1001];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        board[x1][y1]++;
        board[x1][y2]--;
        board[x2][y1]--;
        board[x2][y2]++;
    }

    for (int y = 1; y <= 1000; y++) {
        board[0][y] += board[0][y - 1];
    }

    for (int x = 1; x <= 1000; x++) {
        board[x][0] += board[x - 1][0];

        for (int y = 1; y <= 1000; y++) {
            board[x][y] += board[x][y - 1] + board[x - 1][y] - board[x - 1][y - 1];
        }
    }

    int cnt = 0;

    for (int x = 0; x <= 1000; x++) {
        for (int y = 0; y <= 1000; y++) {
            if (board[x][y] == k) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
