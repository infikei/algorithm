// Solve 2023-02-22
// Update 2025-12-20

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

int a[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int left = 0;
    int right = n - 1;
    int mn = abs(a[0] + a[1]);
    int ans[2] = {a[0], a[1]};

    while (left < right) {
        int s = a[left] + a[right];

        if (abs(s) < mn) {
            mn = abs(s);
            ans[0] = a[left];
            ans[1] = a[right];
        }

        if (s < 0) {
            left++;
        }
        else if (s > 0) {
            right--;
        }
        else break;
    }

    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}
