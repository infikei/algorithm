// Solve 2023-07-29

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

    ll sum[2] = { 0, 0 };

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;

        sum[i & 1] += x;
    }

    if (n == 3 && sum[1] > sum[0]) {
        cout << -1 << '\n';
    }
    else {
        cout << abs(sum[0] - sum[1]) << '\n';
    }

    return 0;
}
