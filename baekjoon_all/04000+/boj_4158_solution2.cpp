// Solve 2023-11-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        unordered_set<int> hs_set;

        for (int i = 0; i < n; i++) {
            int cd;
            cin >> cd;

            hs_set.insert(cd);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int cd;
            cin >> cd;

            if (hs_set.find(cd) != hs_set.end()) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
