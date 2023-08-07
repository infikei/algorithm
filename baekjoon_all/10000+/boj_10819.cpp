// Solve 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, num[8];
bool visited[8];

int dfs(int depth, int val, int prev) {
    if (depth == n) return val;

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        res = max(res, dfs(depth + 1, val + abs(num[i] - prev), num[i]));
        visited[i] = false;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = true;
        ans = max(ans, dfs(1, 0, num[i]));
        visited[i] = false;
    }

    cout << ans << '\n';

    return 0;
}
