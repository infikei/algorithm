// Solve 2023-12-10

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
        int n, m, l;
        cin >> n >> m >> l;

        int ans = n / m;

        // n % m >= (l부터 1까지의 개수)
        if (n % m >= (1 - l + m) % m + 1) {
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
