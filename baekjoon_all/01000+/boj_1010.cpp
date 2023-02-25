// Solve 2022-06-08
// Update 2023-02-21

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int comb[30][30];

int main() {
    FASTIO;

    // 1 <= n <= 29에 대하여 모든 nCr 값을 계산한다.

    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int n = 2; n < 30; n++) {
        comb[n][0] = 1;
        comb[n][n] = 1;
        for (int r = 1; r < n; r++) {
            comb[n][r] = comb[n - 1][r - 1] + comb[n - 1][r];
        }
    }

    // 이제 주어진 입력값에 대한 결과값을 출력한다.

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int west, east;
        cin >> west >> east;
        cout << comb[east][west] << '\n';
    }

    return 0;
}