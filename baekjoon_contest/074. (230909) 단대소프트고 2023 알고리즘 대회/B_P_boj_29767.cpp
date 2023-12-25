// Solve 2023-09-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    priority_queue<ll> pq_maxtop;
    ll prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        prefix_sum += x;

        pq_maxtop.push(prefix_sum);
    }

    ll ans = 0;

    for (int i = 0; i < k; i++) {
        ans += pq_maxtop.top();
        pq_maxtop.pop();
    }

    cout << ans << '\n';

    return 0;
}
