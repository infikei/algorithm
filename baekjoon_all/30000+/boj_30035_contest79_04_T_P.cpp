// Solve 2023-09-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;

    unordered_map<string, int> tier_name_to_idx;
    vector<ll> tier_prefix_sum(t * 4 + 1, 0);
    ll m = n;

    for (int i = 0; i < t; i++) {
        string tier_name, tier_k;
        cin >> tier_name >> tier_k;

        tier_name_to_idx[tier_name] = i;

        ll l = 0;

        if (tier_k.back() == '%') {
            tier_k.pop_back();
            l = m * stoll(tier_k) / 100;
        }
        else {
            l = min(m, stoll(tier_k));
        }

        m -= l;

        ll l4 = (l + 3) / 4;

        for (int j = i * 4 + 1, je = i * 4 + 4; j <= je; j++) {
            tier_prefix_sum[j] = min(l4, l);
            l -= tier_prefix_sum[j];
            tier_prefix_sum[j] += tier_prefix_sum[j - 1];
        }
    }

    string friend_tier_name;
    cin >> friend_tier_name;

    if (m > 0) {
        cout << "Invalid System\n";
    }
    else if (friend_tier_name.back() >= '0' && friend_tier_name.back() <= '9') {
        int friend_tier_detail = friend_tier_name.back() - '1';
        friend_tier_name.pop_back();
        int friend_tier_idx = tier_name_to_idx[friend_tier_name];

        int idx_s = friend_tier_idx * 4 + friend_tier_detail;
        int idx_e = idx_s + 1;

        ll val_s = tier_prefix_sum[idx_s] + 1;
        ll val_e = tier_prefix_sum[idx_e];

        if (val_s > val_e) cout << "Liar\n";
        else cout << val_s << ' ' << val_e << '\n';
    }
    else {
        int friend_tier_idx = tier_name_to_idx[friend_tier_name];

        int idx_s = friend_tier_idx * 4;
        int idx_e = idx_s + 4;

        ll val_s = tier_prefix_sum[idx_s] + 1;
        ll val_e = tier_prefix_sum[idx_e];

        if (val_s > val_e) cout << "Liar\n";
        else cout << val_s << ' ' << val_e << '\n';
    }

    return 0;
}
