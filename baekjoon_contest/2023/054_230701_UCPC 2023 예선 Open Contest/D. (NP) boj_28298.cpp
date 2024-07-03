// Solve 2023-07-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[500][500][26];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    int k_row = 0;
    for (int row = 0; row < n; row++) {
        string line;
        cin >> line;

        int k_col = 0;
        for (int col = 0; col < m; col++) {
            cnt[k_row][k_col][line[col] - 'A']++;

            k_col++;
            if (k_col == k) k_col = 0;
        }

        k_row++;
        if (k_row == k) k_row = 0;
    }

    int ans = 0;
    int sum_cnt = n / k * m / k;
    vector<string> ans_str(k);
    for (int k_row = 0; k_row < k; k_row++) {
        for (int k_col = 0; k_col < k; k_col++) {
            int max_cnt = 0, max_i = 0;

            for (int i = 0; i < 26; i++) {
                if (cnt[k_row][k_col][i] > max_cnt) {
                    max_cnt = cnt[k_row][k_col][i];
                    max_i = i;
                }
            }

            ans_str[k_row].push_back('A' + max_i);
            ans += sum_cnt - max_cnt;
        }
    }

    cout << ans << '\n';

    k_row = 0;
    int k_col_end = m / k;
    for (int row = 0; row < n; row++) {
        for (int k_col = 0; k_col < k_col_end; k_col++) {
            cout << ans_str[k_row];
        }
        cout << '\n';

        k_row++;
        if (k_row == k) k_row = 0;
    }

    return 0;
}
