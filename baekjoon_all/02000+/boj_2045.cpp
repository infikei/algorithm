// Solve 2025-06-01

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

int board[9];
int ans[9];
int h[8][3] = {
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 0, 4, 8 },
    { 2, 4, 6 }
};

bool solution(int s) {
    for (int x = 0; x < 9; x++) {
        ans[x] = board[x];
    }

    int iter = 9;
    int d = 0;

    while (iter > 0) {
        int cnt = 0;
        int r = s;

        for (int i = 0; i < 3; i++) {
            if (ans[h[d][i]] != 0) {
                r -= ans[h[d][i]];
                cnt++;
            }
        }

        if (cnt == 3) {
            if (r != 0) {
                return false;
            }

            iter--;
        }
        else if (cnt == 2) {
            for (int i = 0; i < 3; i++) {
                if (ans[h[d][i]] == 0) {
                    ans[h[d][i]] = r;
                    break;
                }
            }

            iter = 9;
        }
        else {
            iter = 9;
        }

        d++;
        if (d == 8) d = 0;
    }

    for (int x = 0; x < 9; x++) {
        if (ans[x] < 1 || ans[x] > 20000) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    for (int x = 0; x < 9; x++) {
        cin >> board[x];
    }

    for (int s = 3; s <= 60000; s++) {
        if (solution(s)) break;
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    cout << ans[3] << ' ' << ans[4] << ' ' << ans[5] << '\n';
    cout << ans[6] << ' ' << ans[7] << ' ' << ans[8] << '\n';

    return 0;
}
