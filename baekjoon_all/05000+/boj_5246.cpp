// Solve 2023-10-06

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

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int cnt[9] = { 0 };

        for (int i = 0; i < n; i++) {
            int col, row;
            cin >> col >> row;

            cnt[row]++;
        }

        int max_val = 0;

        for (int i = 1; i <= 8; i++) {
            max_val = max(max_val, cnt[i]);
        }

        cout << max_val << '\n';
    }

    return 0;
}
