// Solve 2025-11-04

#pragma GCC optimize("O3")
#pragma GCC target("avx2")
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

    int t;
    cin >> t;

    while (t-- > 0) {
        string n, m;
        cin >> n >> m;
        int cnt01 = 0;
        int cnt10 = 0;

        for (int i = 0; i < size(n); i++) {
            if (n[i] == m[i]) continue;
            else if (n[i] == '0') cnt01++;
            else cnt10++;
        }

        cout << max(cnt01, cnt10) << '\n';
    }

    return 0;
}
