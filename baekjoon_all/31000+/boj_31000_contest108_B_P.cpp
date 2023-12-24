// Solve 2023-12-24

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

    int cnt = 0;

    for (int a = -n; a <= n; a++) {
        if (a == 0) {
            cnt += (2 * n + 1) * (2 * n + 1);
            continue;
        }

        for (int b = -n; b <= n; b++) {
            int c = 1 - a - b;

            if (-n <= c && c <= n) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
