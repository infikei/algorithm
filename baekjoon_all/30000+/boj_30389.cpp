// Solve 2025-11-19

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

unordered_set<string> suffix_set[51];

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        cin >> s;
        string suffix_rev;

        for (int i = 1; i <= size(s); i++) {
            suffix_rev.push_back(s[size(s) - i]);

            if (suffix_set[i].find(suffix_rev) == suffix_set[i].end()) {
                suffix_set[i].insert(suffix_rev);
            }
            else {
                suffix_set[i].erase(suffix_rev);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= 50; i++) {
        ans += size(suffix_set[i]);
    }

    cout << ans << '\n';
    return 0;
}
