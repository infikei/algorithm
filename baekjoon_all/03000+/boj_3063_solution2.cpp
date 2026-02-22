// Solve 2026-02-18

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

int x[4];
int y[4];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
        }

        int area = (x[1] - x[0]) * (y[1] - y[0]);
        int covered_width = max(0, min(x[1], x[3]) - max(x[0], x[2]));
        int covered_height = max(0, min(y[1], y[3]) - max(y[0], y[2]));
        area -= covered_width * covered_height;

        cout << area << '\n';
    }

    return 0;
}
