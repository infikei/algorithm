// Solve 2022-11-26
// Update 2023-09-25

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

    int nm = n + m;

    string s[2];
    cin >> s[0] >> s[1];

    vector<vector<int> > idx_of_1(2, vector<int>());

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < nm; j++) {
            if (s[i][j] == '1') {
                idx_of_1[i].push_back(j);
            }
        }
    }

    ll cnt = 0;

    for (int j = 0; j < m; j++) {
        cnt += abs(idx_of_1[0][j] - idx_of_1[1][j]);
    }

    ll ans = 0, k = cnt / 2;

    if (cnt % 2 == 0) {
        ans = k * k * 2;
    }
    else {
        ans = k * (k + 1) * 2 + 1;
    }

    cout << ans << '\n';

    return 0;
}
