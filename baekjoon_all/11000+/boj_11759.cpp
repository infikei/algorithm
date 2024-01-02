// Solve 2024-01-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s, v1, v2;
    cin >> s >> v1 >> v2;

    int a = s / v1 * v1;
    int b = -1;

    while (a >= 0) {
        if ((s - a) % v2 == 0) {
            b = s - a;
            break;
        }

        a -= v1;
    }

    if (b == -1) {
        cout << "Impossible\n";
    }
    else {
        cout << a / v1 << ' ' << b / v2 << '\n';
    }

    return 0;
}
