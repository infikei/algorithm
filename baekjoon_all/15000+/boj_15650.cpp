// Solve 2022-06-08
// Update 2023-02-17

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

int n, m, seq[9];

void dfs(int depth = 1) {
    if (depth == m + 1) {
        for (int i = 1; i <= m; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = seq[depth - 1] + 1; i <= n; i++) {
        seq[depth] = i;
        dfs(depth + 1);
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    dfs();

    return 0;
}