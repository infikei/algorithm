// Solve 2025-11-07

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

    char prv = 'z';
    int score = 0;
    int v = 0;

    for (char c : s) {
        if (prv < c) {
            v++;
        }
        else {
            v = 1;
        }

        score += v;
        prv = c;
    }

    cout << score << '\n';
    return 0;
}
