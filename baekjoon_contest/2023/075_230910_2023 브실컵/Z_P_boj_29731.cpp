// Solve 2023-09-10
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_set<string> st;
    st.insert("Never gonna give you up");
    st.insert("Never gonna let you down");
    st.insert("Never gonna run around and desert you");
    st.insert("Never gonna make you cry");
    st.insert("Never gonna say goodbye");
    st.insert("Never gonna tell a lie and hurt you");
    st.insert("Never gonna stop");

    int n;
    cin >> n;
    cin.ignore();

    bool ans = false;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (st.find(s) == st.end()) {
            ans = true;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
