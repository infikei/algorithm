// Solve 2022-08-02
// Update 2025-03-02

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
        int n, x;
        cin >> n;

        int ans_min = 1000000;
        int ans_max = -1000000;

        for (int i = 0; i < n; i++) {
            cin >> x;

            ans_min = min(ans_min, x);
            ans_max = max(ans_max, x);
        }

        cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}
