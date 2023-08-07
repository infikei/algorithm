// Solve 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int row_sum[500001], col_sum[500001];
int cnt[4000001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    bool flag = true;

    for (int col = 1; col <= m; col++) {
        cin >> col_sum[col];
    }

    for (int row = 2; row <= n; row++) {
        int x;
        cin >> x;

        row_sum[row] = x - col_sum[1];

        for (int col = 2; col <= m; col++) {
            cin >> x;

            if (flag && x != row_sum[row] + col_sum[col]) {
                flag = false;
            }
        }
    }

    if (!flag) {
        cout << -1 << '\n';
    }
    else {
        int max_cnt = 0, max_val = 0;

        for (int row = 1; row <= n; row++) {
            int now_val = -row_sum[row] + 2000000;
            int now_cnt = ++cnt[now_val];
            if (now_cnt > max_cnt) {
                max_cnt = now_cnt;
                max_val = now_val;
            }
        }

        for (int col = 1; col <= m; col++) {
            int now_val = col_sum[col] + 2000000;
            int now_cnt = ++cnt[now_val];
            if (now_cnt > max_cnt) {
                max_cnt = now_cnt;
                max_val = now_val;
            }
        }

        cout << n + m - max_cnt << '\n';

        max_val -= 2000000;

        for (int row = 1; row <= n; row++) {
            row_sum[row] += max_val;
            if (row_sum[row] == 0) continue;
            cout << "1 " << row << ' ' << row_sum[row] << '\n';
        }

        for (int col = 1; col <= m; col++) {
            col_sum[col] -= max_val;
            if (col_sum[col] == 0) continue;
            cout << "2 " << col << ' ' << col_sum[col] << '\n';
        }
    }

    return 0;
}
