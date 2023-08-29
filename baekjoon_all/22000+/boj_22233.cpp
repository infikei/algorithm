// Solve 2022-08-23
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;

        st.insert(w);
    }

    int cnt = n;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        stringstream ss(s);
        string w;

        while (getline(ss, w, ',')) {
            if (st.find(w) != st.end()) {
                st.erase(w);
                cnt--;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
