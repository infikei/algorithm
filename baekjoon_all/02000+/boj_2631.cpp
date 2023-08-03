// Solve 2023-08-02

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

    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        auto it = lower_bound(dp.begin(), dp.end(), x);

        if (it == dp.end()) {
            dp.push_back(x);
        }
        else if (*it != x) {
            *it = x;
        }
    }

    cout << n - SIZE(dp) << '\n';

    return 0;
}
