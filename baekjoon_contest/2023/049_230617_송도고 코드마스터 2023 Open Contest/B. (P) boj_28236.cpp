// Solve 2023-06-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    int ans = -1, ans2 = 1000000;
    for (int i = 1; i <= k; i++) {
        int f, d;
        cin >> f >> d;

        int tmp = f + n - d;
        if (tmp < ans2) {
            ans2 = tmp;
            ans = i;
        }
    }

    cout << ans << '\n';

    return 0;
}
