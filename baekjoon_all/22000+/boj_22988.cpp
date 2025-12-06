// Solve 2025-12-04

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

ll c[100000];

int main() {
    FASTIO;

    int n;
    ll x;
    cin >> n >> x;
    x *= 2;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] *= 2;
    }

    sort(c, c + n);
    int ans = 0;

    int i = 0;
    int j = n - 1;

    while (j >= 0 && c[j] == x) {
        ans++;
        j--;
    }

    ll half_x = x / 2;
    int r = 0;

    while (i <= j) {
        if (i < j && c[i] + c[j] >= half_x) {
            ans++;
            i++;
            j--;
        }
        else {
            i++;
            r++;

            if (r == 3) {
                ans++;
                r = 0;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
