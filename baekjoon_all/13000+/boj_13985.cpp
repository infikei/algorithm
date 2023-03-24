// Solve 2022-11-02
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

int main() {
    FASTIO;

    char line[5];
    for (int i = 0; i < 5; i++) {
        cin >> line[i];
    }

    if ((int)(line[0] - '0') + (int)(line[2] - '0') == (int)(line[4] - '0')) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
