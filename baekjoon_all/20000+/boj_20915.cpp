// Solve 2026-04-26

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

string s;

ll recur(int depth, ll a, ll b) {
    if (depth == size(s)) {
        return a * b;
    }

    ll na = a * 10 + (s[depth] - '0');
    ll nb = b * 10 + (s[depth] - '0');

    ll ret1 = recur(depth + 1, na, b);
    ll ret2 = recur(depth + 1, a, nb);
    return max(ret1, ret2);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> s;

        for (char& c : s) {
            if (c == '6') {
                c = '9';
            }
        }

        sort(s.begin(), s.end(), greater<char>());

        ll mx = recur(1, s[0] - '0', 0);
        cout << mx << '\n';
    }

    return 0;
}
