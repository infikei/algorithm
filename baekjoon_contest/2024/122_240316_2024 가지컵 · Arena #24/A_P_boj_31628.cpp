// Solve 2024-03-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string board[10][10];

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            cin >> board[x][y];
        }
    }

    bool ans = false;

    for (int x = 0; x < 10; x++) {
        bool flag = true;

        for (int y = 1; y < 10; y++) {
            if (board[x][0] != board[x][y]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = true;
            break;
        }
    }

    if (!ans) {
        for (int y = 0; y < 10; y++) {
            bool flag = true;

            for (int x = 1; x < 10; x++) {
                if (board[0][y] != board[x][y]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans = true;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
