// Solve 2023-03-04

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

    int n, m, k;
    cin >> n >> m >> k;

    if (k < n + m - 1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int row = 1; row <= n; row++) {
            int col_end = row + m;
            for (int col = row; col < col_end; col++) {
                cout << col << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}