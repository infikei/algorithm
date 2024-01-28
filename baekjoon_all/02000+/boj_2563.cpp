// Solve 2022-10-27
// Update 2024-01-28

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

    bool board[100][100] = { false };

    for (int i = 0; i < n; i++) {
        int x_begin, y_begin;
        cin >> x_begin >> y_begin;

        int x_end = x_begin + 10;
        int y_end = y_begin + 10;

        for (int x = x_begin; x < x_end; x++) {
            for (int y = y_begin; y < y_end; y++) {
                board[x][y] = true;
            }
        }
    }

    int ans = 0;

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (board[x][y]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
