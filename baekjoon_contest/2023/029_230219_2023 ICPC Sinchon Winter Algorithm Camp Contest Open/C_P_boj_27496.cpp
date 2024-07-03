// Solve 2023-02-19
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

    int n, l;
    cin >> n >> l;

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cur += a[i];

        if (i >= l) {
            cur -= a[i - l];
        }

        if (cur >= 129 && cur <= 138) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
