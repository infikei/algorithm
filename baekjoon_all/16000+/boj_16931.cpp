// Solve 2023-04-28

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

int graph[100][100];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int ans = n * m * 2;

    for (int row = 0; row < n; row++) {
        cin >> graph[row][0];
        ans += graph[row][0];
        for (int col = 1; col < m; col++) {
            cin >> graph[row][col];
            ans += abs(graph[row][col] - graph[row][col - 1]);
        }
        ans += graph[row][m - 1];
    }

    for (int col = 0; col < m; col++) {
        ans += graph[0][col];
        for (int row = 1; row < n; row++) {
            ans += abs(graph[row][col] - graph[row - 1][col]);
        }
        ans += graph[n - 1][col];
    }

    cout << ans << '\n';

    return 0;
}
