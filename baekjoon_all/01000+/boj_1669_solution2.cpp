// Solve 2025-07-22

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

    int x, y;
    cin >> x >> y;
    y -= x;
    ll low = -1;
    ll high = 100000;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll max_dist = 0;

        if (mid % 2 == 0) {
            max_dist = (mid / 2) * (mid / 2 + 1);
        }
        else {
            max_dist = (mid / 2 + 1) * (mid / 2 + 1);
        }

        if (max_dist >= y) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    cout << high << '\n';
    return 0;
}
