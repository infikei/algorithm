// Solve 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        cout << n << ' ';

        while (n >= 10) {
            int n2 = 1;

            while (n > 0) {
                n2 *= n % 10;
                n /= 10;
            }

            n = n2;
            cout << n << ' ';
        }

        cout << '\n';
    }

    return 0;
}
