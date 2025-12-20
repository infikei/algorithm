// Solve 2025-12-20

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

ll a[5000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    ll mn = LLINF;
    ll ans[3] = {0};

    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }

            if (right == i) {
                right--;
                continue;
            }

            ll s2 = a[left] + a[right];
            ll s3 = s2 + a[i];

            if (abs(s3) < mn) {
                mn = abs(s3);
                ans[0] = a[i];
                ans[1] = a[left];
                ans[2] = a[right];
            }

            if (s2 < -a[i]) {
                left++;
            }
            else if (s2 > -a[i]) {
                right--;
            }
            else break;
        }
    }

    sort(ans, ans + 3);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}
