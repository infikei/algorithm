// Solve 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int comb[29][29];

int main() {
    FASTIO;

    comb[1][0] = 1;
    comb[1][1] = 1;

    for (int i = 2; i < 29; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    int n, m, k;
    cin >> n >> m >> k;

    if (k == 0) {
        cout << comb[n + m - 2][n - 1] << '\n';
    }
    else {
        int row = (k - 1) / m;
        int col = k - 1 - m * row;

        cout << comb[row + col][row] * comb[n + m - 2 - row - col][n - 1 - row] << '\n';
    }

    return 0;
}
