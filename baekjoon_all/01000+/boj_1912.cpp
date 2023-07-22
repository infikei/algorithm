// Solve 2022-06-03
// Update 2023-07-22

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

    int val = 0, max_val = -1000;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        val += x;
        if (val > max_val) {
            max_val = val;
        }

        if (val < 0) {
            val = 0;
        }
    }

    cout << max_val << '\n';

    return 0;
}
