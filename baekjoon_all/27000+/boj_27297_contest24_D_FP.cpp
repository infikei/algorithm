// Solve 2023-01-30
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

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> p(n, vector<ll>(m));

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> p[i][j];
        }
    }

    vector<ll> f(n);
    ll dist_sum = 0;

    for (int i = 0; i < n; i++) {
        sort(p[i].begin(), p[i].end());
        f[i] = p[i][m / 2];

        for (int j = 0; j < m; j++) {
            dist_sum += abs(f[i] - p[i][j]);
        }
    }

    cout << dist_sum << '\n';

    for (int i = 0; i < n; i++) {
        cout << f[i] << ' ';
    }

    cout << '\n';

    return 0;
}
