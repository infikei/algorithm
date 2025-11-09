// Solve 2025-11-08

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

int cnt[5];

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = cnt[4];
    cnt[4] = 0;

    ans += cnt[3];
    cnt[1] = max(0, cnt[1] - cnt[3]);
    cnt[3] = 0;

    ans += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2] == 1) {
        ans++;
        cnt[1] = max(0, cnt[1] - 2);
        cnt[2] = 0;
    }

    ans += cnt[1] / 4;
    cnt[1] %= 4;

    if (cnt[1] > 0) {
        ans++;
        cnt[1] = 0;
    }

    cout << ans << '\n';
    return 0;
}
