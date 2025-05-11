// Solve 2025-05-11

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

    int n;
    cin >> n;

    int ans = 0;
    int cnt[4] = { 0 };

    for (int i = 0; i < n; i++) {
        string bulb;
        cin >> bulb;

        for (int j = 1; j < bulb.size(); j++) {
            if (bulb[j - 1] != bulb[j]) {
                ans++;
            }
        }

        cnt[(bulb[0] - '0') * 2 + (bulb.back() - '0')]++;
    }

    if (cnt[1] == 0 && cnt[2] == 0) {
        if (cnt[0] == 0 || cnt[3] == 0) {
            cout << ans << '\n';
            return 0;
        }

        cout << ans + 1 << '\n';
        return 0;
    }

    if (abs(cnt[1] - cnt[2]) >= 2) {
        ans += max(cnt[1], cnt[2]) - min(cnt[1], cnt[2]) - 1;
    }

    cout << ans << '\n';

    return 0;
}
