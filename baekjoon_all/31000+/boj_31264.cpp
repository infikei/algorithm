// Solve 2026-04-15

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

ll s[100000];

int main() {
    FASTIO;

    int n, m;
    ll a;
    cin >> n >> m >> a;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s + n);
    ll low = s[0];
    ll high = max(a, s[n - 1]);
    ll mn = max(a, s[n - 1]);

    while (low <= high) {
        ll mid = (low + high) / 2;

        ll ability = mid;
        int prv_idx = 0;

        for (int i = 0; i < m; i++) {
            int idx = upper_bound(s + prv_idx, s + n, ability) - s;
            idx--;
            ability += s[idx];
            prv_idx = idx;
        }

        ll score = ability - mid;

        if (score >= a) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << mn << '\n';
    return 0;
}
