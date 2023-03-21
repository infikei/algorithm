// Solve 2023-03-20

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

bool check[201][201];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        check[x][y] = true;
        check[y][x] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (check[j][i]) {
                continue;
            }
            for (int k = j + 1; k <= n; k++) {
                if (check[k][i] || check[k][j]) {
                    continue;
                }
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
