// Solve 2023-11-18

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

    vector<int> a, b, x;

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;

        a.push_back(ai);
    }

    for (int i = 0; i < n; i++) {
        int bi;
        cin >> bi;

        b.push_back(bi);
    }

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;

        x.push_back(xi);
    }

    int ans;

    if (abs(b[0] - a[0]) % x[0] != 0) {
        ans = -1;
    }
    else {
        ans = abs(b[0] - a[0]) / x[0];
    }

    for (int i = 1; i < n; i++) {
        if (abs(b[i] - a[i]) % x[i] != 0) {
            ans = -1;
            break;
        }

        int tmp = abs(b[i] - a[i]) / x[i];

        if (ans % 2 != tmp % 2) {
            ans = -1;
            break;
        }

        ans = max(ans, tmp);
    }

    cout << ans << '\n';

    return 0;
}
