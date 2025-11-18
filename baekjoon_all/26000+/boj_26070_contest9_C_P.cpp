// Solve 2022-11-26
// Update 2025-11-18

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

    uint gomgom[3];
    uint ticket[3];

    for (int i = 0; i < 3; i++) {
        cin >> gomgom[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> ticket[i];
    }

    uint cnt = 0;

    // 1st chance

    for (int i = 0; i < 3; i++) {
        uint t = min(ticket[i], gomgom[i]);
        cnt += t;
        gomgom[i] -= t;
        ticket[i] -= t;
    }

    // 2nd chance

    for (int i = 0; i < 3; i++) {
        int ii = (i + 1) % 3;

        uint t = min(ticket[i] / 3, gomgom[ii]);
        cnt += t;
        gomgom[ii] -= t;
        ticket[i] -= t * 3;
    }

    // last chance

    for (int i = 0; i < 3; i++) {
        int ii = (i + 1) % 3;
        int iii = (i + 2) % 3;

        if (gomgom[i] == 0 && gomgom[ii] == 0 && gomgom[iii] > 0) {
            uint t = (ticket[i] / 3 + ticket[ii]) / 3;
            cnt += min(t, gomgom[iii]);
        }
    }

    cout << cnt << '\n';
    return 0;
}
