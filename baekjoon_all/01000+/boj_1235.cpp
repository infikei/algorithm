// Solve 2024-01-14

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

    vector<string> ids(n);

    for (string &id : ids) {
        cin >> id;
    }

    int id_length = SIZE(ids[0]);

    for (int k = 1; k <= id_length; k++) {
        set<string> st;
        bool flag = true;

        for (string &id : ids) {
            string id_back = id.substr(id_length - k, k);

            if (st.find(id_back) == st.end()) {
                st.insert(id_back);
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << k << '\n';
            break;
        }
    }

    return 0;
}
