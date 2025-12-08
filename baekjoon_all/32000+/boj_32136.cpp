// Solve 2025-12-07

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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int n;
ll a[300000];

ll get_val(int x) {
    ll ret = 0;

    for (int i = 0; i < n; i++) {
        ret = max(ret, abs(i - x) * a[i]);
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;

    while (low + 2 < high) {
        int mid1 = (low * 2 + high) / 3;
        int mid2 = (low + high * 2) / 3;

        ll mid1_val = get_val(mid1);
        ll mid2_val = get_val(mid2);

        if (mid1_val > mid2_val) {
            low = mid1;
        }
        else {
            high = mid2;
        }
    }

    ll mn = LLINF;

    for (int i = low; i <= high; i++) {
        mn = min(mn, get_val(i));
    }

    cout << mn << '\n';
    return 0;
}
