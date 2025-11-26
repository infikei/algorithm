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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;

        char ch = s[0];
        int len = 1;

        for (int i = 1; i < size(s); i++) {
            if (ch == s[i]) {
                len++;
            }
            else {
                cout << len << ch;
                ch = s[i];
                len = 1;
            }
        }

        cout << len << ch << '\n';
    }

    return 0;
}
