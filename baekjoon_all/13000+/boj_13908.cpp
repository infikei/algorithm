// Solve 2022-08-20
// Update 2023-03-24

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

int n, m, cnt;
bool check[10];

void dfs(int depth = 0, int k = m) {
    if (k == 0) {
        int j = 1;
        for (int i = 0; i < n - depth; i++) {
            j *= 10;
        }
        cnt += j;
        return;
    }
    if (depth == n) {
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (check[i]) {
            check[i] = false;
            dfs(depth + 1, k - 1);
            check[i] = true;
        }
        else {
            dfs(depth + 1, k);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        check[x] = true;
    }

    dfs();
    cout << cnt << '\n';

    return 0;
}
