// Solve 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int row_sum[500001], col_sum[500001];

int main() {
    FASTIO;

    int n, m, q;
    cin >> n >> m >> q;

    for (int qi = 0; qi < q; qi++) {
        int cmd, rc, v;
        cin >> cmd >> rc >> v;

        if (cmd == 1) {
            row_sum[rc] += v;
        }
        else {
            col_sum[rc] += v;
        }
    }

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            cout << row_sum[row] + col_sum[col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
