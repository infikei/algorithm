// Solve 2025-12-08

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

int tmp[5];

int main() {
    FASTIO;

    set<int> st;

    for (int i = 0; i < 5; i++) {
        int v;
        cin >> v;
        st.insert(v);
    }

    int mn = 5;

    for (int i = 1; i <= 5; i++) {
        int cnt = 0;

        for (int j = 0; j < 5; j++) {
            if (st.find(i + j) == st.end()) {
                cnt++;
            }
        }

        mn = min(mn, cnt);
    }

    cout << mn << '\n';
    return 0;
}
