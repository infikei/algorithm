// Solve 2023-09-24

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

    vector<int> vec(n);

    for (int &x : vec) {
        cin >> x;
    }

    unordered_set<int> hs;

    for (int j = 1; j < n; j++) {
        hs.insert(vec[j] - vec[0]);
    }

    for (int i = 1; i < n; i++) {
        unordered_set<int> hs_res;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            int y = abs(vec[j] - vec[i]);

            if (hs.find(y) != hs.end()) {
                hs_res.insert(y);
            }
        }

        swap(hs, hs_res);

        if (hs.empty()) break;
    }

    vector<int> ans_vec;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        ans_vec.push_back(*it);
    }

    sort(ans_vec.begin(), ans_vec.end());

    cout << SIZE(ans_vec) << '\n';

    for (int &x : ans_vec) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
