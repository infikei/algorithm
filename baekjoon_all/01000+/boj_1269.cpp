// Solve 2022-06-03
// Update 2023-10-10

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

    int a_and_b_cnt = 0;

    for (int i = 0; i < b_cnt; i++) {
        int x;
        cin >> x;

        if (st.find(x) != st.end()) {
            a_and_b_cnt++;
        }
    }

    cout << a_cnt + b_cnt - a_and_b_cnt * 2 << '\n';

    return 0;
}
