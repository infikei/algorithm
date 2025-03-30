// Solve 2025-03-29

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

    int n, d, k;
    cin >> n >> d >> k;

    int max_s = 0;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        max_s = max(max_s, s);
    }

    int interval_clear = k / max_s;
    int ans = (d - 1) / interval_clear;

    cout << ans << '\n';

    return 0;
}
