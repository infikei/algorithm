// Solve 2025-12-10

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

int arr[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        while (m-- > 0) {
            int v;
            cin >> v;
            arr[i] += v;
        }
    }

    sort(arr, arr + n, greater<int>());
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (ll) (i + 1) * arr[i];
    }

    cout << ans << '\n';
    return 0;
}
