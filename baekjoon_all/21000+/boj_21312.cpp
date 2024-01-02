// Solve 2024-01-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;

        if (x % 2 == 1) {
            odd.push_back(x);
        }
        else {
            even.push_back(x);
        }
    }

    int ans = 1;

    if (odd.empty()) {
        for (int &x : even) {
            ans *= x;
        }
    }
    else {
        for (int &x : odd) {
            ans *= x;
        }
    }

    cout << ans << '\n';

    return 0;
}
