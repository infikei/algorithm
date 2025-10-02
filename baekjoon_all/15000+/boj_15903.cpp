// Solve 2025-10-01

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    priority_queue<ll, vector<ll>, greater<ll>> pq_mintop;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq_mintop.push(x);
    }

    while (m-- > 0) {
        ll x = pq_mintop.top();
        pq_mintop.pop();
        x += pq_mintop.top();
        pq_mintop.pop();
        pq_mintop.push(x);
        pq_mintop.push(x);
    }

    ll ans = 0;

    while (!pq_mintop.empty()) {
        ans += pq_mintop.top();
        pq_mintop.pop();
    }

    cout << ans << '\n';
    return 0;
}
