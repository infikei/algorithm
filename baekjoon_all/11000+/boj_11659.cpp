// Solve 2022-06-23
// Update 2023-03-04

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

int dp[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dp[i] = dp[i - 1] + x;
    }

    for (int i = 0; i < m; i++) {
        int b, e;
        cin >> b >> e;
        cout << dp[e] - dp[b - 1] << '\n';
    }

    return 0;
}