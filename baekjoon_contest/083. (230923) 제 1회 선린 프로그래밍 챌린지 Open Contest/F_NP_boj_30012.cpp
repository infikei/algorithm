// Solve 2023-09-25
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int frog_s, n;
    cin >> frog_s >> n;

    vector<int> frog_e(n);

    for (int &x : frog_e) {
        cin >> x;
    }

    int k, l;
    cin >> k >> l;

    int k2 = k * 2;
    int min_val = 2e9;
    int min_idx = 0;

    for (int i = 0; i < n; i++) {
        int dist = abs(frog_e[i] - frog_s);
        int val = 0;

        if (dist <= k2) {
            val = k2 - dist;
        }
        else {
            val = (dist - k2) * l;
        }

        if (val < min_val) {
            min_val = val;
            min_idx = i + 1;
        }
    }

    cout << min_val << ' ' << min_idx << '\n';;

    return 0;
}
