// Solve 2022-07-15
// Update 2023-09-02

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

    int coin[10];

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
        cnt += k / coin[i];
        k %= coin[i];

        if (k == 0) break;
    }

    cout << cnt << '\n';

    return 0;
}
