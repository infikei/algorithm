// Solve 2022-09-15
// Update 2026-04-08

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

    bool fbi = false;

    for (int u = 1; u <= 5; u++) {
        string s;
        cin >> s;

        for (int i = 2; i < size(s); i++) {
            if (s[i - 2] == 'F' && s[i - 1] == 'B' && s[i] == 'I') {
                cout << u << ' ';
                fbi = true;
                break;
            }
        }
    }

    if (!fbi) {
        cout << "HE GOT AWAY!";
    }

    cout << '\n';
    return 0;
}
