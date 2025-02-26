// Solve 2025-02-26

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll s(int k) {
    ll res = 0;
    int left = 1;

    while (left <= k) {
        int cur = k / left;
        int right = k / cur;
        res += (right - left + 1) * cur;
        left = right + 1;
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans = 0;
    int left = 1;
    ll s_prev = 0;

    while (left <= n) {
        int cur = n / left;
        int right = n / cur;
        ll s_cur = s(right);
        ans += (s_cur - s_prev) * cur;
        s_prev = s_cur;
        left = right + 1;
    }

    cout << ans << '\n';

    return 0;
}
