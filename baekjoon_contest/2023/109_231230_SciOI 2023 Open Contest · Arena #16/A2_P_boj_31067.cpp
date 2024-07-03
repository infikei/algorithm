// Solve 2023-12-30

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

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (v[i - 1] >= v[i]) {
            if (v[i - 1] < v[i] + k) {
                v[i] += k;
                ans++;
            }
            else {
                ans = -1;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
