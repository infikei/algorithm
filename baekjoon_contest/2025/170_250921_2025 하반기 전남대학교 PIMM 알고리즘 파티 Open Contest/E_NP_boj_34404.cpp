// Solve 2025-09-21

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
    vector<pii> rectangles;

    for (int i = 0; i < n; i++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        rectangles.emplace_back(x + p, y + q);
    }

    ll a, b;
    cin >> a >> b;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (rectangles[i].second >= a * rectangles[i].first + 2 * b) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
