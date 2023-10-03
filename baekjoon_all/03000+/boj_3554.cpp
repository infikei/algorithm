// Solve 2023-10-03

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

    int arr[50001];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int mi = 0; mi < m; mi++) {
        int k, l, r;
        cin >> k >> l >> r;

        if (k == 1) {
            for (int i = l; i <= r; i++) {
                arr[i] = arr[i] * arr[i] % 2010;
            }
        }
        else {
            int ans = 0;

            for (int i = l; i <= r; i++) {
                ans += arr[i];
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
