// Solve 2024-05-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, x, s;
    cin >> n >> x >> s;

    bool ans = false;

    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;

        if (c <= x && p > s) {
            ans = true;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
