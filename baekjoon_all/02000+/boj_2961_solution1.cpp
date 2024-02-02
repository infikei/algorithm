// Solve 2022-08-20
// Update 2024-02-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, ans;
int s[10], b[10];

void dfs(int depth = 0, int s_prod = 1, int b_sum = 0) {
    if (depth == n) {
        if (b_sum == 0) return;

        ans = min(ans, abs(s_prod - b_sum));
        return;
    }

    dfs(depth + 1, s_prod, b_sum);
    dfs(depth + 1, s_prod * s[depth], b_sum + b[depth]);
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    ans = abs(s[0] - b[0]);
    dfs();

    cout << ans << '\n';

    return 0;
}
