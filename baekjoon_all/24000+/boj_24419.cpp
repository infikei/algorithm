// Solve 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000007;
int comb[2001][2001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1, ie = n * 2; i <= ie; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    cout << comb[n * 2][n] << ' ' << n * n << '\n';

    return 0;
}
