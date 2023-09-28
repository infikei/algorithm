// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x, b;
    cin >> x >> b;

    string ans;
    bool ans_sign = false;

    if (x == 0) ans = "0";

    if (x < 0 && b > 0) {
        ans_sign = true;
        x = -x;
    }

    while (x != 0) {
        int r = x % b;
        if (r < 0) r -= b;

        ans.push_back('0' + r);
        x -= r;
        x /= b;
    }

    if (ans_sign) ans.push_back('-');

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
