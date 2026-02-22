// Solve 2026-02-18

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

    for (int ti = 1; ti <= t; ti++) {
        int g;
        cin >> g;

        unordered_set<int> st;

        while (g-- > 0) {
            int c;
            cin >> c;

            if (st.find(c) == st.end()) {
                st.insert(c);
            }
            else {
                st.erase(c);
            }
        }

        cout << "Case #" << ti << ": ";

        for (int c : st) {
            cout << c;
        }

        cout << '\n';
    }

    return 0;
}
