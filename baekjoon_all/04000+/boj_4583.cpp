// Solve 2025-11-20

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

char mirror[128];

int main() {
    FASTIO;

    mirror['b'] = 'd';
    mirror['d'] = 'b';
    mirror['p'] = 'q';
    mirror['q'] = 'p';
    mirror['i'] = 'i';
    mirror['o'] = 'o';
    mirror['v'] = 'v';
    mirror['w'] = 'w';
    mirror['x'] = 'x';

    while (true) {
        string s;
        cin >> s;

        if (s == "#") break;

        bool flag = true;

        for (char& c : s) {
            if (mirror[c] == 0) {
                flag = false;
                break;
            }

            c = mirror[c];
        }

        if (!flag) {
            cout << "INVALID" << '\n';
            continue;
        }

        reverse(s.begin(), s.end());
        cout << s << '\n';
    }

    return 0;
}
