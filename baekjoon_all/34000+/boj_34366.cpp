// Solve 2025-11-20

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

    int m;
    cin >> m;

    int mx = 0;
    int mn = INF;
    int month_mx = 0;
    int month_mn = INF;

    while (m-- > 0) {
        int s;
        cin >> s;
        int month_sum = 0;

        while (s-- > 0) {
            int x;
            cin >> x;
            month_sum += x;
            mx = max(mx, x);
            mn = min(mn, x);
        }

        month_mx = max(month_mx, month_sum);
        month_mn = min(month_mn, month_sum);
    }

    cout << mx << '\n';
    cout << mn << '\n';
    cout << month_mx << '\n';
    cout << month_mn << '\n';
    return 0;
}
