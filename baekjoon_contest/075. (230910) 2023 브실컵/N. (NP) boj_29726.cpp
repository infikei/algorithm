// Solve 2023-09-13

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

    int a[200000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = n - m - 1;
    int left_min = a[i];
    int ans = a[j] - a[i];

    while (j < n) {
        left_min = min(left_min, a[i]);
        ans = max(ans, a[j] - left_min);
        i++; j++;
    }

    cout << ans << '\n';

    return 0;
}
