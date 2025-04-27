// Solve 2025-04-25

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

    while (true) {
        int c, d;
        cin >> c >> d;

        if (c == 0 && d == 0) break;

        int ans = min(c * 30 + d * 40, min(c * 35 + d * 30, c * 40 + d * 20));
        cout << ans << '\n';
    }

    return 0;
}
