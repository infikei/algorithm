// Solve 2023-02-05
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll n, k, a, b, ans;

ll comb(ll a, ll b) {
    ll res = 1;

    if (b > a / 2) {
        b = a - b;
    }

    ll ii = a;
    for (ll i = 1; i <= b; i++) {
        res *= ii;
        res /= i;

        ii--;
    }

    return res;
}

ll xor_cnt(ll a, ll b) {
    ll res = 0, xor_a_b = a ^ b;

    while (xor_a_b > 0) {
        if (xor_a_b % 2 == 1) res++;

        xor_a_b >>= 1;
    }

    return res;
}

void cnt(ll s, ll e, ll l, ll r) {
    if (l > r) return;

    if (l == r) {
        if (xor_cnt(l, n) == k) ans++;
        return;
    }

    if (s == l && e == r) {
        ll len_tmp = e - s + 1;
        ll right_len = 0;

        while (len_tmp % 2 == 0) {
            right_len++;
            len_tmp >>= 1;
        }

        ll s_left = s >> right_len;
        ll n_left = n >> right_len;
        ll left_xor_cnt = xor_cnt(s_left, n_left);

        if (left_xor_cnt <= k && right_len >= k - left_xor_cnt) {
            ans += comb(right_len, k - left_xor_cnt);
        }
        return;
    }

    ll mid = (e - s + 1) >> 1;
    cnt(s, s + mid - 1, max(l, s), min(r, s + mid - 1));
    cnt(s + mid, e, max(l, s + mid), min(r, e));
}

int main() {
    FASTIO;

    cin >> n >> k >> a >> b;

    ll tmp = 1;

    while (tmp <= b) {
        tmp <<= 1;
    }
    tmp--;

    cnt(0, tmp, a, b);

    cout << ans << '\n';

    return 0;
}
