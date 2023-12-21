// Solve 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    for (int x = -1000; x <= 1000; x++) {
        if (x * x + 2 * a * x + b == 0) {
            cout << x << ' ';
        }
    }

    cout << '\n';

    return 0;
}
