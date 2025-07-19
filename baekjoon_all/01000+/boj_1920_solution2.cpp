// Solve 2022-06-06
// Update 2025-07-19

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

unordered_set<int> hs;

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int x;
        cin >> x;
        hs.insert(x);
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int x;
        cin >> x;
        cout << (hs.find(x) == hs.end() ? 0 : 1) << '\n';
    }

    return 0;
}
