// Solve 2022-06-03
// Update 2023-03-14

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

    int p[4][2];
    for (int i = 0; i < 3; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    for (int j = 0; j < 2; j++) {
        if (p[0][j] == p[1][j]) {
            p[3][j] = p[2][j];
        }
        else if (p[0][j] == p[2][j]) {
            p[3][j] = p[1][j];
        }
        else {
            p[3][j] = p[0][j];
        }
    }

    cout << p[3][0] << ' ' << p[3][1] << '\n';

    return 0;
}
