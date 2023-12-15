// Solve 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int t0;
    cin >> t0;

    int gift = 0;

    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;

        if (t <= t0 - k) {
            gift++;
        }

        t0 = t;
    }

    cout << gift << '\n';

    return 0;
}
