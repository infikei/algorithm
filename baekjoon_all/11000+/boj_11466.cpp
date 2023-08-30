// Solve 2023-08-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(9);

    int h, w;
    cin >> h >> w;

    if (h > w) swap(h, w);

    if (w >= 3 * h) cout << h << '\n';
    else if (2 * w >= 3 * h) cout << w / 3.0 << '\n';
    else cout << h / 2.0 << '\n';

    return 0;
}
