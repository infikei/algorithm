// Solve 2022-12-21
// Update 2023-09-06

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
        int n;
        cin >> n;

        int a[10001];

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int now = 1, ans = 1;

        while (true) {
            int next = a[now];

            if (next == n) break;
            else if (next == 0) {
                ans = 0;
                break;
            }

            a[now] = 0;
            now = next;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
