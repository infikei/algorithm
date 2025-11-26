// Solve 2025-11-24

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

int cnt[1001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        memset(cnt, 0, sizeof cnt);

        int v;
        cin >> v;

        while (v-- > 0) {
            int s;
            cin >> s;
            cnt[s]++;
        }

        int mx = 0;
        int mx_num = 0;

        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                mx_num = i;
            }
        }

        cout << mx_num << '\n';
    }

    return 0;
}
