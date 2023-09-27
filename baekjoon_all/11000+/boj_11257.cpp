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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int idx, a, b, c;
        cin >> idx >> a >> b >> c;

        if (a + b + c >= 55 && a >= 11 && b >= 8 && c >= 12) {
            cout << idx << ' ' << a + b + c << " PASS\n";
        }
        else {
            cout << idx << ' ' << a + b + c << " FAIL\n";
        }
    }

    return 0;
}
