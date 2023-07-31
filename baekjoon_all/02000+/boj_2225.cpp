// Solve 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000000;
int comb[400][400];

int main() {
    FASTIO;

    comb[0][0] = 1;
    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int i = 2; i < 400; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    int n, k;
    cin >> n >> k;

    cout << comb[n + k - 1][n] << '\n';

    return 0;
}
