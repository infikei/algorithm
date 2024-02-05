// Solve 2022-08-01
// Update 2024-02-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<int> vec;

    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }

    vector<int> ans(n);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        idx += k - 1;
        idx %= SIZE(vec);
        ans[i] = vec[idx];
        vec.erase(vec.begin() + idx);
    }

    cout << '<' << ans[0];

    for (int i = 1; i < n; i++) {
        cout << ", " << ans[i];
    }

    cout << ">\n";

    return 0;
}
