// Solve 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<pii> vec;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int x;
            cin >> x;

            if (x == 1) {
                vec.emplace_back(row, col);
            }
        }
    }

    int ans = abs(vec[0].first - vec[1].first) + abs(vec[0].second - vec[1].second);

    cout << ans << '\n';

    return 0;
}
