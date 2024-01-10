// Solve 2024-01-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; i++) {
        if (i % x == 0) {
            if (i % y == 0) {
                cout << "FizzBuzz\n";
            }
            else {
                cout << "Fizz\n";
            }
        }
        else {
            if (i % y == 0) {
                cout << "Buzz\n";
            }
            else {
                cout << i << '\n';
            }
        }
    }

    return 0;
}
