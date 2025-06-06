// Solve 2025-06-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string s, t;
    cin >> s >> t;

    set<char> st;

    for (char c : s) {
        st.insert(c);
    }

    string ans;

    for (char c : t) {
        if (st.find(c) == st.end()) {
            ans.push_back(c);
        }
    }

    cout << ans << '\n';

    return 0;
}
