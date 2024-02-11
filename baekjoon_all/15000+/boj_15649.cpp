// Solve 2022-06-08
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, m;
int seq[8];

void dfs(int depth = 0, int selected = 0) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if ((selected & 1 << i) == 0) {
            seq[depth] = i;
            dfs(depth + 1, selected | 1 << i);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    dfs();

    return 0;
}
