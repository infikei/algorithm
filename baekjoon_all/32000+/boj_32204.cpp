// Solve 2026-02-08

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

    int n, prv;
    cin >> n >> prv;
    ll s = 1;
    int a = 1;
    int b = 1;

    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;

        a++;
        b++;

        if (prv < cur) {
            a = b;
        }
        else if (prv > cur) {
            b = 1;
        }

        s += a;
        prv = cur;
    }

    cout << s << '\n';
    return 0;
}
