// Solve 2023-12-31

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

    vector<int> cnt_1(n + 1, 0);
    vector<int> cnt_2(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (k > 0) {
            cnt_1[k - 1]++;
        }
        else {
            cnt_2[-k + 1]++;
        }
    }

    for (int i = n; i > 0; i--) {
        cnt_1[i - 1] += cnt_1[i];
    }

    for (int i = 0; i < n; i++) {
        cnt_2[i + 1] += cnt_2[i];
    }

    vector<int> ans_vec;

    for (int i = 0; i <= n; i++) {
        if (i == cnt_1[i] + cnt_2[i]) {
            ans_vec.push_back(i);
        }
    }

    cout << SIZE(ans_vec) << '\n';

    if (!ans_vec.empty()) {
        for (int &ans : ans_vec) {
            cout << ans << ' ';
        }
    }

    cout << '\n';

    return 0;
}
