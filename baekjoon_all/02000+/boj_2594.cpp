// Solve 2025-11-09

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

    int n;
    cin >> n;

    vector<pii> rides;

    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        t1 = (t1 / 100 * 60) + (t1 % 100) - 10;
        t2 = (t2 / 100 * 60) + (t2 % 100) + 10;
        rides.emplace_back(t1, t2);
    }

    sort(rides.begin(), rides.end());
    int cur = 10 * 60;
    int mx = 0;

    for (auto& ride : rides) {
        int t1 = ride.first;
        int t2 = ride.second;

        mx = max(mx, t1 - cur);
        cur = max(cur, t2);
    }

    mx = max(mx, 22 * 60 - cur);
    cout << mx << '\n';
    return 0;
}
