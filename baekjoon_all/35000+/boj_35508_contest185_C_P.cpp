// Solve 2026-04-26

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
using piii = pair<int, pii>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    vector<piii> v;
    v.push_back({0, {0, 0}});
    int mx = 0;

    for (int i = 1; i <= n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        v.push_back({t, {a, b}});
        mx = max(mx, a + b);
    }

    sort(v.begin(), v.end());
    int j = 0;
    int mx_b = 0;

    for (int i = n; i >= 0; i--) {
        int t = v[i].first;
        int a = v[i].second.first;

        while (j + 1 <= n && v[j + 1].first + t <= d) {
            j++;
            mx_b = max(mx_b, v[j].second.second);
        }

        mx = max(mx, a + mx_b);
    }

    cout << mx << '\n';
    return 0;
}
