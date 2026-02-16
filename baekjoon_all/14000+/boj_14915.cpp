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

    int m, n;
    cin >> m >> n;

    string s;

    while (m > 0) {
        int r = m % n;
        m /= n;

        if (r >= 10) {
            s.push_back('A' + (r - 10));
        }
        else {
            s.push_back('0' + r);
        }
    }

    if (s.empty()) {
        s = "0";
    }

    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}
