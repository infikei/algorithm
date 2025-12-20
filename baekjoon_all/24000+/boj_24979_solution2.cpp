// Solve 2025-12-19

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

int c_prefix[200001];
int o_prefix[200001];
int w_prefix[200001];

int main() {
    FASTIO;

    string s;
    cin >> s;

    for (int i = 1; i <= size(s); i++) {
        c_prefix[i] = c_prefix[i - 1];
        o_prefix[i] = o_prefix[i - 1];
        w_prefix[i] = w_prefix[i - 1];

        if (s[i - 1] == 'C') {
            c_prefix[i] ^= 1;
        }
        else if (s[i - 1] == 'O') {
            o_prefix[i] ^= 1;
        }
        else {
            w_prefix[i] ^= 1;
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;

        int c = c_prefix[r] ^ c_prefix[l - 1];
        int o = o_prefix[r] ^ o_prefix[l - 1];
        int w = w_prefix[r] ^ w_prefix[l - 1];

        if (c == 1 && o == 0 && w == 0) {
            cout << 'Y';
        }
        else if (c == 0 && o == 1 && w == 1) {
            cout << 'Y';
        }
        else {
            cout << 'N';
        }
    }

    cout << '\n';
    return 0;
}
