// Solve 2022-06-02
// Update 2023-08-02

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

    string space(n, ' '), star;

    for (int row = 1; row <= n; row++) {
        space.pop_back();
        star += "*";

        cout << space << star << '\n';
    }

    return 0;
}
