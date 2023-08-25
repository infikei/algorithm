// Solve 2023-08-25

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

    if (n == 1) cout << 0 << '\n';
    else {
        int ans = n - 1;

        for (int i = 2, ie = sqrt(n); i <= ie; i++) {
            if (n % i == 0) {
                ans = n - n / i;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
