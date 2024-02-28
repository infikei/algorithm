// Solve 2022-06-03
// Update 2024-02-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int memo[1000001];
    memo[1] = 0;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1];

        if (i % 3 == 0) {
            memo[i] = min(memo[i], memo[i / 3]);
        }

        if (i % 2 == 0) {
            memo[i] = min(memo[i], memo[i / 2]);
        }

        memo[i]++;
    }

    cout << memo[n] << '\n';

    return 0;
}
