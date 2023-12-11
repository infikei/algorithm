// Solve 2022-11-22
// Update 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;

        int ans = 0;

        for (int a = 1; a < n; a++) {
            int tmp = a * a + m;

            for (int b = a + 1; b < n; b++) {
                if ((tmp + b * b) % (a * b) == 0) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
