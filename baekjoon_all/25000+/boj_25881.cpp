// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, n;
    cin >> a >> b >> n;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if (c <= 1000) {
            cout << c << ' ' << c * a << '\n';
        }
        else {
            cout << c << ' ' << 1000 * a + (c - 1000) * b << '\n';
        }
    }

    return 0;
}
