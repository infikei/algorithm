// Solve 2023-12-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int xs = 0, ys = 2000;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (y < ys) {
            xs = x;
            ys = y;
        }
    }

    cout << xs << ' ' << ys << '\n';

    return 0;
}
