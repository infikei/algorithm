// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, limit;
    cin >> n >> limit;

    limit += 60;

    int ans = 0;

    if (n <= limit) {
        ans = n * 1500;
    }
    else {
        ans = limit * 1500 + (n - limit) * 3000;
    }

    cout << ans << '\n';

    return 0;
}
