// Solve 2022-10-01
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

    for (int row = 1; row <= n; row++) {
        if (row % 2 == 0) {
            cout << ' ';
        }

        for (int i = 1; i <= n; i++) {
            cout << "* ";
        }
        cout << '\n';
    }

    return 0;
}
