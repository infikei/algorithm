// Solve 2023-12-16

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

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    vector<int> ans(n);
    ans[1] = a[1] - a[0];
    ans[2] = a[2] - a[0];

    for (int i = 3; i < n; i++) {
        if (i % 2 == 0) {
            ans[i] = min(a[i] - a[i - 1] + ans[i - 2], a[i] - a[i - 2] + ans[i - 3]);
        }
        else {
            ans[i] = a[i] - a[i - 1] + ans[i - 2];
        }
    }

    cout << ans[n - 1] << '\n';

    return 0;
}
