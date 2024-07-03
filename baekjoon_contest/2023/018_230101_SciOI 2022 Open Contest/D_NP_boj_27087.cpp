// Solve 2024-02-21

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

    while (t-- > 0) {
        int a, b, c, p;
        cin >> a >> b >> c >> p;

        int cnt = 0;

        if (a % p == 0) cnt++;
        if (b % p == 0) cnt++;
        if (c % p == 0) cnt++;

        cout << (cnt >= 2) << '\n';
    }

    return 0;
}
