// Solve 2025-12-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

#ifdef BOJ
using lll = __int128;
using lld = __float128;
#else
using lll = long long;
using lld = long double;
#endif

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
vector<int> pos[26];

lll count_alphabet(char ch, lll idx) {
    lll q = idx / (lll) size(s);
    lll r = idx % (lll) size(s);

    lll a = (lll) size(pos[ch - 'A']) * q;
    lll b = upper_bound(pos[ch - 'A'].begin(), pos[ch - 'A'].end(), (int) r) - pos[ch - 'A'].begin();
    return a + b;
}

int main() {
    FASTIO;

    ll n;
    cin >> n >> s;

    for (int i = 0; i < 26; i++) {
        char ch = 'A' + i;

        for (int j = 0; j < size(s); j++) {
            if (s[j] == ch) {
                pos[i].push_back(j + 1);
            }
        }
    }

    int k;
    cin >> k;

    while (k-- > 0) {
        ll a;
        char ch;
        cin >> a >> ch;

        lll r = a * (lll) (a + 1) / 2;
        lll l = (a - 1) * (lll) a / 2;

        lll cnt_r = count_alphabet(ch, r);
        lll cnt_l = count_alphabet(ch, l);
        cout << (ll) (cnt_r - cnt_l) << '\n';
    }

    return 0;
}
