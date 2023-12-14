// Solve 2022-07-05
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_gcd(int a, int b) {
    int r = a % b;

    if (r == 0) return b;

    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int arr[100];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += calc_gcd(arr[i], arr[j]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
