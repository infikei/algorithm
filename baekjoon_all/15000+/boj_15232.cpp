// Solve 2022-11-18
// Update 2023-08-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
