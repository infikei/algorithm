// Solve 2023-03-01
// Update 2025-02-21

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        int cur = 0;

        for (int y = 0; y < n; y++) {
            if (board[x][y] == '.') {
                cur++;
            }
            else {
                if (cur >= 2) {
                    ans++;
                }

                cur = 0;
            }
        }

        if (cur >= 2) {
            ans++;
        }
    }

    cout << ans << ' ';
    ans = 0;

    for (int y = 0; y < n; y++) {
        int cur = 0;

        for (int x = 0; x < n; x++) {
            if (board[x][y] == '.') {
                cur++;
            }
            else {
                if (cur >= 2) {
                    ans++;
                }

                cur = 0;
            }
        }

        if (cur >= 2) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
