// Solve 2025-03-28

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

    int n, c, s;
    cin >> n >> c >> s;

    int cur = 1;
    int ans = 0;

    if (cur == s) {
        ans++;
    }

    while (c-- > 0) {
        int x;
        cin >> x;

        cur += x;

        if (cur > n) {
            cur -= n;
        }
        else if (cur <= 0) {
            cur += n;
        }

        if (cur == s) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
