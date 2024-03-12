// Solve 2022-11-02
// Update 2024-03-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, a, b;
    cin >> n >> a >> b;

    int ans = min(n, a / 2 + b);
    cout << ans << '\n';

    return 0;
}
