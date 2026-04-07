// Solve 2026-03-21

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

    int n, m;
    cin >> n >> m;

    bool ans = true;

    for (int i = 0; i < n; i++) {
        int a_cnt = 0;

        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'A') {
                a_cnt++;
            }
        }

        if (a_cnt != 1) {
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';
    return 0;
}
