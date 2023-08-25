// Solve 2022-08-04
// Update 2023-08-25

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

    bool check[1001] = { false };
    int ans = 0, cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (check[i]) continue;

        check[i] = true;
        if (++cnt == k) {
            ans = i;
            break;
        }

        for (int j = i + i; j <= n; j += i) {
            if (check[j]) continue;

            check[j] = true;
            if (++cnt == k) {
                ans = j;
                break;
            }
        }

        if (ans != 0) break;
    }

    cout << ans << '\n';

    return 0;
}
