// Solve 2023-04-10

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

    int scores[2][9];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> scores[i][j];
        }
    }

    bool ans = false;
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
        a += scores[0][i];
        if (a > b) {
            ans = true;
            break;
        }

        b += scores[1][i];
    }

    if (ans) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
