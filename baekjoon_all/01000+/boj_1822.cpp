// Solve 2023-09-14
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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    set<int> st;

    while (n-- > 0) {
        int x;
        cin >> x;
        st.insert(x);
    }

    while (m-- > 0) {
        int x;
        cin >> x;
        st.erase(x);
    }

    cout << size(st) << '\n';

    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << ' ';
    }

    cout << '\n';
    return 0;
}
