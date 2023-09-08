// Solve 2023-09-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    unordered_map<ll, ll> hs;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;

        hs[x]++;
    }

    ll max_val = 0, max_cnt = 0;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        if (it->second > max_cnt || it->second == max_cnt && it->first < max_val) {
            max_val = it->first;
            max_cnt = it->second;
        }
    }

    cout << max_val << '\n';

    return 0;
}
