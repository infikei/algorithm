// Solve 2023-11-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h, l, a, b;
    cin >> h >> l >> a >> b;

    if (a <= 2 * h && b <= l) {
        cout << "YES\n";
    }
    else if (b <= 2 * h && a <= l) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
