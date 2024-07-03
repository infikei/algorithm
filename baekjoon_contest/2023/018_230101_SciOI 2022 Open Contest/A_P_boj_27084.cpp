// Solve 2023-01-01
// Update 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<int, int> hs_map;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        hs_map[x]++;
    }

    ll ans = 1;

    for (auto it = hs_map.begin(); it != hs_map.end(); it++) {
        ans = ans * (it->second + 1) % MOD;
    }

    cout << --ans << '\n';

    return 0;
}
