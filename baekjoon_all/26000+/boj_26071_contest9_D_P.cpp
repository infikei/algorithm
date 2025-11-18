// Solve 2022-11-26
// Update 2025-11-18

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

    int top = n - 1;
    int bottom = 0;
    int left = n - 1;
    int right = 0;

    for (int x = 0; x < n; x++) {
        string row;
        cin >> row;

        for (int y = 0; y < n; y++) {
            if (row[y] == 'G') {
                top = min(top, x);
                bottom = max(bottom, x);
                left = min(left, y);
                right = max(right, y);
            }
        }
    }

    int ans = 0;

    if (top < bottom) {
        ans += min(n - 1 - top, bottom);
    }

    if (left < right) {
        ans += min(n - 1 - left, right);
    }

    cout << ans << '\n';
    return 0;
}
