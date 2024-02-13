// Solve 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int comb[201][201];

int main() {
    FASTIO;

    comb[0][0] = 1;
    comb[1][0] = 1;
    comb[1][1] = 1;

    for (int i = 2; i <= 200; i++) {
        comb[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

            if (comb[i][j] >= 1'000'000'001) {
                comb[i][j] = 1'000'000'001;
            }
        }
    }

    int n, m, k;
    cin >> n >> m >> k;

    if (k > comb[n + m][n]) {
        cout << -1 << '\n';
    }
    else {
        int iter = n + m;
        string ans;

        while (iter-- > 0) {
            if (n == 0) {
                ans.push_back('z');
                continue;
            }
            else if (m == 0) {
                ans.push_back('a');
                continue;
            }

            if (k <= comb[n + m - 1][n - 1]) {
                n--;
                ans.push_back('a');
            }
            else {
                k -= comb[n + m - 1][n - 1];
                m--;
                ans.push_back('z');
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
