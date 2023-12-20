// Solve 2022-09-09
// Update 2023-12-20

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

    string space(n - 1, ' ');
    string star = "*";

    cout << space << star << '\n';

    int iter = n - 1;

    while (--iter >= 0) {
        space.pop_back();
        star += " *";

        cout << space << star << '\n';
    }

    return 0;
}
