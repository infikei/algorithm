// Solve 2023-01-19
// Update 2023-08-30

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

    int prefix_sum[100001] = { 0 };

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        prefix_sum[i] = prefix_sum[i - 1] + x;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << prefix_sum[e] - prefix_sum[s - 1] << '\n';
    }

    return 0;
}
