// Solve 2023-08-02

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

    ll a[100001];
    ll a_sum = 0, b_sum = 0;

    for (int i = 1; i <= n; i++) {
        ll ai, bi;
        cin >> ai >> bi;

        a[i] = ai;
        b_sum += bi;
    }

    sort(a + 1, a + (n + 1));

    for (ll i = 1; i <= n; i++) {
        a_sum += a[i] * i;
    }

    cout << a_sum + b_sum << '\n';

    return 0;
}
