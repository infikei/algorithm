// Solve 2025-08-17

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

    string s;
    cin >> s;

    bool hiss = false;

    for (int i = 1; i < size(s); i++) {
        if (s[i - 1] == 's' && s[i] == 's') {
            hiss = true;
            break;
        }
    }

    cout << (hiss ? "hiss" : "no hiss") << '\n';
    return 0;
}
