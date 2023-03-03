// Solve 2022-08-03
// Update 2023-03-03

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

int a[100][100], b[100][100], ans[100][100];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> a[row][col];
        }
    }
    cin >> m >> k;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < k; col++) {
            cin >> b[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < k; col++) {
            for (int i = 0; i < m; i++) {
                ans[row][col] += a[row][i] * b[i][col];
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < k; col++) {
            cout << ans[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}