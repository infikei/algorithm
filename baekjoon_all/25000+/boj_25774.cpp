// Solve 2026-04-23

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

    int d1, m1, y1, n;
    cin >> d1 >> m1 >> y1 >> n;

    int d2, m2, y2;
    cin >> d2 >> m2 >> y2;

    int idx1 = d1 + m1 * 30 + y1 * 360;
    int idx2 = d2 + m2 * 30 + y2 * 360;
    int diff = idx2 - idx1;

    int weekday = (n - 1 + diff) % 7 + 1;
    cout << weekday << '\n';
    return 0;
}
