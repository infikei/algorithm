// Solve 2022-09-15
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
    string space2 = "* ";

    cout << space << "*\n";

    int iter = n - 2;

    while (--iter >= 0) {
        space.pop_back();

        cout << space << space2 << "*\n";

        space2 += "  ";
    }

    if (n > 1) {
        cout << string(n * 2 - 1, '*') << '\n';
    }

    return 0;
}
