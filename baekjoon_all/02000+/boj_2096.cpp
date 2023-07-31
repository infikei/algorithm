// Solve 2023-07-31

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

    vector<vector<int> > dp_max(2, vector<int>(3));
    vector<vector<int> > dp_min(2, vector<int>(3));

    for (int i = 1; i <= n; i++) {
        dp_max[0] = dp_max[1];
        dp_min[0] = dp_min[1];

        int a, b, c;
        cin >> a >> b >> c;

        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + a;
        dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + b;
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + c;

        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + a;
        dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + b;
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + c;
    }

    cout << *max_element(dp_max[1].begin(), dp_max[1].end()) << ' ';
    cout << *min_element(dp_min[1].begin(), dp_min[1].end()) << ' ';

    return 0;
}
