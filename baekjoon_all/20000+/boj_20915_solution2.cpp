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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;

        for (char& c : s) {
            if (c == '6') {
                c = '9';
            }
        }

        sort(s.begin(), s.end(), greater<char>());

        ll a = 0;
        ll b = 0;

        for (int i = 0; i < size(s); i++) {
            if (a > b) {
                b = b * 10 + (s[i] - '0');
            }
            else {
                a = a * 10 + (s[i] - '0');
            }
        }

        cout << a * b << '\n';
    }

    return 0;
}
