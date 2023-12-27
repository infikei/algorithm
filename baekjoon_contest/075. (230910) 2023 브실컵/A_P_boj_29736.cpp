// Solve 2023-09-10
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

    int a, b, k, x;
    cin >> a >> b >> k >> x;

    int s = max(a, k - x);
    int e = min(b, k + x);
    int cnt = e - s + 1;

    if (cnt <= 0) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << cnt << '\n';
    }

    return 0;
}
