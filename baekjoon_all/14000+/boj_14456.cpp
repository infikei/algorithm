// Solve 2025-12-08

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

    int n;
    cin >> n;

    int cnt1 = 0;
    int cnt2 = 0;

    while (n-- > 0) {
        int a, b;
        cin >> a >> b;

        if (a == b) continue;

        if (a - b == 1 || a - b == -2) cnt1++;
        else cnt2++;
    }

    cout << max(cnt1, cnt2) << '\n';
    return 0;
}
