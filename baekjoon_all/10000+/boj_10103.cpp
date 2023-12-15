// Solve 2022-11-04
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int scores[2] = { 100, 100 };
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x > y) {
            scores[1] -= x;
        }
        else if (x < y) {
            scores[0] -= y;
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << scores[i] << '\n';
    }

    return 0;
}
