// Solve 2025-06-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int l, r, s;
        cin >> l >> r >> s;

        int ans = min((s - l) * 2 + 1, (r - s) * 2);
        cout << ans << '\n';
    }

    return 0;
}
