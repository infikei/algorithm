// Solve 2022-06-03
// Update 2023-03-15

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

    int k;
    cin >> k;

    int pt[6][2];
    for (int i = 0; i < 6; i++) {
        cin >> pt[i][0] >> pt[i][1];
    }

    int key = 0;
    for (int i = 0; i < 6; i++) {
        if (pt[i][0] == pt[(i + 2) % 6][0] && pt[(i + 1) % 6][0] == pt[(i + 3) % 6][0])
            key = i;
    }

    int area = pt[(key + 4) % 6][1] * pt[(key + 5) % 6][1];
    area -= pt[(key + 1) % 6][1] * pt[(key + 2) % 6][1];

    cout << area * k << '\n';

    return 0;
}
