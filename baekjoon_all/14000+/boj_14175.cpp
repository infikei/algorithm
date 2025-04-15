// Solve 2025-04-13

// 유사한 문제 : 20205번

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

string board[10];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        for (int i = 0; i < k; i++) {
            for (int y = 0; y < m; y++) {
                for (int j = 0; j < k; j++) {
                    cout << board[x][y];
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
