// Solve 2024-04-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int min_p6, min_p1;
    cin >> min_p6 >> min_p1;

    for (int i = 1; i < m; i++) {
        int p6, p1;
        cin >> p6 >> p1;

        min_p6 = p6 < min_p6 ? p6 : min_p6;
        min_p1 = p1 < min_p1 ? p1 : min_p1;
    }

    int a = n / 6;
    int b = n % 6;
    int ans = min({ min_p6 * ((n - 1) / 6 + 1), min_p6 * a + min_p1 * b, min_p1 * n});
    cout << ans << '\n';

    return 0;
}
