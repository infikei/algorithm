// Solve 2025-12-08
// Update 2025-12-10

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

vector<int> pos[26];

int main() {
    FASTIO;

    ll n;
    string s;
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

        ll cnt = a / size(s) * size(pos[ch - 'A']);
        ll l, r;

        if (a % 2 == 0) {
            l = ((a - 1) % size(s)) * (a / 2 % size(s)) % size(s);
            r = (a / 2 % size(s)) * ((a + 1) % size(s)) % size(s);
        }
        else {
            l = ((a - 1) / 2 % size(s)) * (a % size(s)) % size(s);
            r = (a % size(s)) * ((a + 1) / 2 % size(s)) % size(s);
        }

        l = (l == 0 ? size(s) : l);
        r = (r == 0 ? size(s) : r);
        auto it_l = upper_bound(pos[ch - 'A'].begin(), pos[ch - 'A'].end(), l);
        auto it_r = upper_bound(pos[ch - 'A'].begin(), pos[ch - 'A'].end(), r);

        if (l <= r) {
            cnt += it_r - it_l;
        }
        else {
            cnt += size(pos[ch - 'A']) - (int) (it_l - it_r);
        }

        cout << cnt << '\n';
    }

    return 0;
}
