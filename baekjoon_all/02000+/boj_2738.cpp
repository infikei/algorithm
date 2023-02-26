// Solve 2022-07-20
// Update 2023-02-26

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

int main() {
    FASTIO;

    const int MAX_SIZE = 100;

    int n, m;
    cin >> n >> m;

    int a[MAX_SIZE][MAX_SIZE];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> a[row][col];
        }
    }

    int b[MAX_SIZE][MAX_SIZE];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> b[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cout << a[row][col] + b[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}