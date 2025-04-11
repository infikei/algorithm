// Solve 2025-04-11

// 유사한 문제 : 14175번

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

int board[10][10];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    for (int x = 0; x < n; x++) {
        for (int i = 0; i < k; i++) {
            for (int y = 0; y < n; y++) {
                for (int j = 0; j < k; j++) {
                    cout << board[x][y] << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
