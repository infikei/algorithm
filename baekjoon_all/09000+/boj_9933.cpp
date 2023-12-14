// Solve 2023-10-01
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_set<string> st;
    string ans;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        st.insert(s);

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        if (st.find(rev_s) != st.end()) {
            ans = s;
        }
    }

    cout << SIZE(ans) << ' ' << ans[SIZE(ans) / 2] << '\n';

    return 0;
}
