// Solve 2025-12-06

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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    ll memo[5] = {LLINF, LLINF, LLINF, LLINF, LLINF};

    for (int i = 0; i < n; i++) {
        char c = s[i];
        ll a;
        cin >> a;

        if (c == 'U') {
            memo[0] = min(memo[0], a);
        }
        else if (c == 'O') {
            memo[1] = min(memo[1], memo[0] + a);
        }
        else if (c == 'S') {
            memo[2] = min(memo[2], memo[1] + a);
        }
        else if (c == 'P') {
            memo[3] = min(memo[3], memo[2] + a);
        }
        else {
            memo[4] = min(memo[4], memo[3] + a);
        }
    }

    cout << (memo[4] == LLINF ? -1 : memo[4]) << '\n';
    return 0;
}
