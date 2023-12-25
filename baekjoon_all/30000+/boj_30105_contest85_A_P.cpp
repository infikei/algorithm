// Solve 2023-09-24
// Update 2023-12-25

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
        unordered_set<int> new_hs;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            int y = abs(vec[j] - vec[i]);

            if (hs.find(y) != hs.end()) {
                new_hs.insert(y);
            }
        }

        swap(hs, new_hs);

        if (hs.empty()) break;
    }

    vector<int> ans;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        ans.push_back(*it);
    }

    sort(ans.begin(), ans.end());

    cout << SIZE(ans) << '\n';

    if (SIZE(ans) > 0) {
        for (int &x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
