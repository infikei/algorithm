// Solve 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ans[11] = { 0, 1, 2, 2, 3, 3, 3, 2, 2, 1, 1 };

    int n;
    cin >> n;

    cout << ans[n] << '\n';

    return 0;
}
