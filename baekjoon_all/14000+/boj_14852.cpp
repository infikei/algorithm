// Solve 2023-07-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll prev_a = 1, a = 2, s = 3;
    for (int i = 1; i < n; i++) {
        swap(prev_a, a);
        a += (s << 1);
        a %= MOD;
        s += a;
        s %= MOD;
    }

    cout << a << '\n';

    return 0;
}
