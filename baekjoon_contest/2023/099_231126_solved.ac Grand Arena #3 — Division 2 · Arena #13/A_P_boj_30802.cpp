// Solve 2023-11-26

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

    int sizes[6];

    for (int i = 0; i < 6; i++) {
        cin >> sizes[i];
    }

    int t, p;
    cin >> t >> p;

    int ans1 = 0;

    for (int i = 0; i < 6; i++) {
        ans1 += (sizes[i] + t - 1) / t;
    }

    cout << ans1 << '\n';
    cout << n / p << ' ' << n % p << '\n';

    return 0;
}
