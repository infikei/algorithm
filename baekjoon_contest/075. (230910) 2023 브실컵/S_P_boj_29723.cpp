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

    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<string, int> hs;

    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;

        hs[s] = p;
    }

    int ans = 0;

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;

        ans += hs[s];
        hs.erase(s);
    }

    vector<int> vec;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        vec.push_back(it->second);
    }

    sort(vec.begin(), vec.end());

    int ans_min = ans;
    int ans_max = ans;

    for (int i = 0, ii = SIZE(vec) - 1, ie = m - k; i < ie; i++, ii--) {
        ans_min += vec[i];
        ans_max += vec[ii];
    }

    cout << ans_min << ' ' << ans_max << '\n';

    return 0;
}
