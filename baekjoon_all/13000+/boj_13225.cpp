// Solve 2023-12-21

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

        int cnt = 0;

        for (int i = 1, ie = sqrt(n); i <= ie; i++) {
            if (n % i != 0) continue;

            int ii = n / i;

            if (i == ii) cnt++;
            else cnt += 2;
        }

        cout << n << ' ' << cnt << '\n';
    }

    return 0;
}
