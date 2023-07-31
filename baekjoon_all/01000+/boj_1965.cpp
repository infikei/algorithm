// Solve 2023-05-08
// Update 2023-07-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int box[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), box[i]) - dp.begin();

        if (pos == SIZE(dp)) {
            dp.push_back(box[i]);
        }
        else if (box[i] < dp[pos]) {
            dp[pos] = box[i];
        }
    }

    cout << SIZE(dp) << '\n';

    return 0;
}
