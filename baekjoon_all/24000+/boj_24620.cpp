// Solve 2025-11-06

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

int count(int d, int s, set<int>& p_sum) {
    int ret = 0;

    for (int i = d; i <= s; i += d) {
        if (p_sum.find(i) == p_sum.end()) return 0;

        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int s = 0;
        set<int> p_sum;

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;

            if (v > 0) {
                s += v;
                p_sum.insert(s);
            }
        }

        int mn = n - 1;

        if (s == 0) {
            mn = 0;
        }

        for (int i = 1, sqrt_s = sqrt(s); i <= sqrt_s; i++) {
            if (s % i != 0) continue;

            mn = min(mn, n - count(i, s, p_sum));
            mn = min(mn, n - count(s / i, s, p_sum));
        }

        cout << mn << '\n';
    }

    return 0;
}
