// Solve 2023-12-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, s;
    cin >> n >> s;

    int v = 0;

    for (int i = 1; i < n; i++) {
        int dv;
        cin >> dv;

        v += dv;
        if (v > s) v--;
    }

    int dv;
    cin >> dv;

    v += dv;

    cout << v << '\n';

    return 0;
}
