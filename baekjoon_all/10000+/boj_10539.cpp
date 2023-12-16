// Solve 2022-12-15
// Update 2023-12-16

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

    vector<ll> b(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    ll pa = 0;

    for (int i = 1; i <= n; i++) {
        ll a = b[i] * i;

        cout << a - pa << ' ';

        pa = a;
    }

    cout << '\n';

    return 0;
}
