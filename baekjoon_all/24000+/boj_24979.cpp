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

int prefix[200001];

int main() {
    FASTIO;

    string s;
    cin >> s;

    // C를 10, O를 01, W를 11로 설정하면
    // C + O = W, C + W = O, O + O = W,
    // C + C = '', O + O = '', W + W = '' 를 만족한다.

    for (int i = 1; i <= size(s); i++) {
        prefix[i] = prefix[i - 1];

        if (s[i - 1] == 'C') {
            prefix[i] ^= 2;
        }
        else if (s[i - 1] == 'O') {
            prefix[i] ^= 1;
        }
        else {
            prefix[i] ^= 3;
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;

        int b = prefix[r] ^ prefix[l - 1];

        cout << (b == 2 ? 'Y' : 'N');
    }

    cout << '\n';
    return 0;
}
