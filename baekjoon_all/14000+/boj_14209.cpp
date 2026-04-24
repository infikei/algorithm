// Solve 2026-04-09

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

int conv[128];

int main() {
    FASTIO;

    conv['A'] = 4;
    conv['K'] = 3;
    conv['Q'] = 2;
    conv['J'] = 1;

    int n;
    cin >> n;

    int score = 0;

    while (n-- > 0) {
        string s;
        cin >> s;

        for (char c : s) {
            score += conv[c];
        }
    }

    cout << score << '\n';
    return 0;
}
