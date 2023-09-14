// Solve 2023-09-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a_cnt, b_cnt;
    cin >> a_cnt >> b_cnt;

    set<int> st;

    for (int i = 0; i < a_cnt; i++) {
        int x;
        cin >> x;

        st.insert(x);
    }

    for (int i = 0; i < b_cnt; i++) {
        int x;
        cin >> x;

        st.erase(x);
    }

    cout << SIZE(st) << '\n';

    if (SIZE(st) > 0) {
        for (auto it = st.begin(); it != st.end(); it++) {
            cout << *it << ' ';
        }

        cout << '\n';
    }

    return 0;
}
