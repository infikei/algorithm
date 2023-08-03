// Solve 2023-02-14
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

    string star = "*", space(n - 1, ' ');

    for (int iter = n - 1; iter > 0; iter--) {
        cout << star << space << space << star << '\n';

        star += "*";
        space.pop_back();
    }

    cout << star << space << space << star << '\n';

    for (int iter = n - 1; iter > 0; iter--) {
        star.pop_back();
        space += " ";

        cout << star << space << space << star << '\n';
    }

    return 0;
}
