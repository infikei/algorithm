// Solve 2023-11-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 998'244'353;

ll calc_power(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }

        a *= a;
        a %= MOD;
        b >>= 1;
    }

    return res;
}

int calc_modinv(int a) {
    return calc_power(a, MOD - 2);
}

struct Comb{
    vector<int> fact, rfact;

    Comb(int sz) : fact(sz + 1), rfact(sz + 1) {
        fact[0] = 1;

        for (int i = 1; i <= sz; i++) {
            fact[i] = (ll)fact[i - 1] * i % MOD;
        }

        rfact[sz] = calc_modinv(fact[sz]);

        for (int i = sz - 1; i >= 0; i--) {
            rfact[i] = (ll)rfact[i + 1] * (i + 1) % MOD;
        }
    }

    int c(int n, int r) {
        return (ll)fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;

        for (int j = 0; j < len; j++) {
            int x;
            cin >> x;

            cnt[x]++;
        }
    }

    unordered_map<int, int> cnt_cnt;

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        cnt_cnt[it->second]++;
    }

    Comb comb(1'000'000);
    vector<int> ans(n + 1, 0);

    for (auto it = cnt_cnt.begin(); it != cnt_cnt.end(); it++) {
        int now_cnt = it->first;

        for (int k = 1; k <= now_cnt; k++) {
            ans[k] = (ans[k] + (ll)comb.c(now_cnt, k) * it->second % MOD) % MOD;;
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << '\n';
    }

    return 0;
}
