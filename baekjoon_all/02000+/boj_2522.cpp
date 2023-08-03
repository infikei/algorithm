// Solve 2022-09-09
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

    string space(n - 1, ' '), star = "*";

    for (int iter = n - 1; iter > 0; iter--) {
        cout << space << star << '\n';

        space.pop_back();
        star += "*";
    }

    for (int iter = n - 1; iter > 0; iter--) {
        cout << space << star << '\n';

        space += " ";
        star.pop_back();
    }

    cout << space << star << '\n';

    return 0;
}
