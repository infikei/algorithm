// Solve 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 14579;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    int ans = 1;

    for (int i = a; i <= b; i++) {
        int val = i * (i + 1) / 2;

        ans = ans * (val % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
