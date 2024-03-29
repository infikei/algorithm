// Solve 2023-08-22 (BOJ First Solved)
// Update 2023-12-26

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

    int a[200000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    double ans = a[0];

    for (int i = 1; i < n; i++) {
        ans = (ans + a[i]) * 0.5;
    }

    SETPRECISION(12);

    cout << ans << '\n';

    return 0;
}
