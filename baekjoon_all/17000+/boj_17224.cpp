// Solve 2026-02-15

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

    int n, l, k;
    cin >> n >> l >> k;

    int easy_cnt = 0;
    int hard_cnt = 0;

    while (n-- > 0) {
        int sub1, sub2;
        cin >> sub1 >> sub2;

        if (sub2 <= l) {
            hard_cnt++;
        }
        else if (sub1 <= l) {
            easy_cnt++;
        }
    }

    int s = 0;
    int x = min(hard_cnt, k);
    k -= x;
    s += x * 140;

    x = min(easy_cnt, k);
    k -= x;
    s += x * 100;

    cout << s << '\n';
    return 0;
}
