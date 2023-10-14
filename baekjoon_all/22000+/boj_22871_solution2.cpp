// Solve 2022-08-02
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll board[5001], dp[5001][5001];

ll power(int a, int b) {
    return (b - a) * (1 + abs(board[a] - board[b]));
}

ll solve(int now, int next) {
    if (now == next) return 0;

    if (dp[now][next] > 0) return dp[now][next];

    ll res = power(now, next);

    for (int i = now + 1; i < next; i++) {
        res = min(res, max(solve(now, i), power(i, next)));
    }

    return dp[now][next] = res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    cout << solve(1, n) << '\n';

    return 0;
}
