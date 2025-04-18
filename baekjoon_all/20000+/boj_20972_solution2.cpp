// Solve 2025-04-18

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

int row_sum[1000][2];
int col_sum[1000][2];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int cur;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> cur;

            row_sum[x][y % 2] += cur;
            col_sum[y][x % 2] += cur;
        }
    }

    int ans = 0;
    int ans2 = 0;

    for (int i = 0; i < n; i++) {
        ans += max(row_sum[i][0], row_sum[i][1]);
        ans2 += max(col_sum[i][0], col_sum[i][1]);
    }

    cout << max(ans, ans2) << '\n';

    return 0;
}
