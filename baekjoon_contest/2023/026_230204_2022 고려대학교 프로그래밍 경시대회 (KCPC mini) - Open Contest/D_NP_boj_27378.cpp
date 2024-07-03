// Solve 2023-02-05
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll calc_comb(ll a, ll b) {
    ll res = 1;
    b = min(b, a - b);
    ll ii = a;

    for (ll i = 1; i <= b; i++) {
        res *= ii;
        res /= i;
        ii--;
    }

    return res;
}

int count_1_in_xor(ll x, ll y) {
    int res = 0;
    ll xor_x_y = x ^ y;

    while (xor_x_y > 0) {
        if (xor_x_y & 1) {
            res++;
        }

        xor_x_y >>= 1;
    }

    return res;
}

void count_ans(ll &n, int &k, ll &ans, ll s, ll e, ll l, ll r) {
    if (l > r) return;

    if (l == r) {
        if (count_1_in_xor(l, n) == k) ans++;
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
        int left_cnt_1_in_xor = count_1_in_xor(s_left, n_left);

        if (left_cnt_1_in_xor <= k && right_len >= k - left_cnt_1_in_xor) {
            ans += calc_comb(right_len, k - left_cnt_1_in_xor);
        }

        return;
    }

    ll mid = (e - s + 1) >> 1;
    count_ans(n, k, ans, s, s + mid - 1, max(l, s), min(r, s + mid - 1));
    count_ans(n, k, ans, s + mid, e, max(l, s + mid), min(r, e));
}

int main() {
    FASTIO;

    ll n, a, b;
    int k;
    cin >> n >> k >> a >> b;

    ll bb = 1;

    while (bb <= b) {
        bb <<= 1;
    }

    bb--;
    ll ans = 0;
    count_ans(n, k, ans, 0, bb, a, b);

    cout << ans << '\n';

    return 0;
}
