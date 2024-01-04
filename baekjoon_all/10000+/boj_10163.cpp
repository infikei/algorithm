// Solve 2024-01-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int board[1001][1001] = { 0 };

    for (int i = 1; i <= n; i++) {
        int x0, y0, dx, dy;
        cin >> x0 >> y0 >> dx >> dy;

        int x1 = x0 + dx;
        int y1 = y0 + dy;

        for (int x = x0; x < x1; x++) {
            for (int y = y0; y < y1; y++) {
                board[x][y] = i;
            }
        }
    }

    int cnt[101] = { 0 };

    for (int x = 0; x < 1001; x++) {
        for (int y = 0; y < 1001; y++) {
            cnt[board[x][y]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}
