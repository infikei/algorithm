// Solve 2025-11-19

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

int cnt[10];

int main() {
    FASTIO;

    int last = 0;

    for (int i = 0; i < 100; i++) {
        int d;
        cin >> d;
        d %= 10;

        if (++cnt[d] == 10) {
            last = d == 0 ? 10 : d;
        }
    }

    cout << last << '\n';
    return 0;
}
