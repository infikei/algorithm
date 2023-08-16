// Solve 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, k;
int c[10][10], ans = -100000;
int choice[10];

void dfs(int depth = 0, int idx = 0, int val = 0) {
    if (depth == k) {
        ans = max(ans, val);
        return;
    }

    for (int i = idx; i < n; i++) {
        int nval = val;
        for (int j = 0; j < depth; j++) {
            nval += c[i][choice[j]];
        }

        choice[depth] = i;

        dfs(depth + 1, i + 1, nval);
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    dfs();

    cout << ans << '\n';

    return 0;
}
