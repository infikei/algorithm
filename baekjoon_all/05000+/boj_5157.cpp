// Solve 2023-10-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int c, b, n, r;
        cin >> c >> b >> n >> r;

        vector<bool> received(c + 1, false);

        for (int bi = 0; bi < b; bi++) {
            int x;
            cin >> x;

            received[x] = true;
        }

        vector<int> received_value(c + 1);

        for (int ni = 0; ni < n; ni++) {
            int ci, pi;
            cin >> ci >> pi;

            if (received[ci]) {
                received_value[ci] += pi * r / 100;
            }
        }

        int ans = 0;

        for (int ci = 1; ci <= c; ci++) {
            if (received[ci]) {
                ans += received_value[ci];
            }
        }

        if (ti >= 2) cout << '\n';

        cout << "Data Set " << ti << ":\n" << ans << '\n';
    }

    return 0;
}
