// Solve 2023-11-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 998244353;

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

    vector<int> ans(n + 1, 0);

    for (auto it = cnt_cnt.begin(); it != cnt_cnt.end(); it++) {
        int now_cnt = it->first;
        ll comb = 1;

        for (int k = 1; k <= now_cnt; k++) {
            comb = comb * (now_cnt + 1 - k) % MOD;
            comb = comb * calc_power(k, MOD - 2) % MOD;
            ans[k] += comb * it->second % MOD;
            ans[k] %= MOD;
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << '\n';
    }

    return 0;
}
