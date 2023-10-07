// Solve 2023-10-07

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

        int sum_of_proper_divisors = 0;

        for (int i = 1, ie = sqrt(n); i <= ie; i++) {
            if (n % i != 0) continue;

            int ii = n / i;

            if (i != n) sum_of_proper_divisors += i;

            if (ii != i && ii != n) sum_of_proper_divisors += ii;
        }

        if (sum_of_proper_divisors < n) {
            cout << n << " DEFICIENT\n";
        }
        else if (sum_of_proper_divisors > n) {
            cout << n << " ABUNDANT\n";
        }
        else {
            cout << n << " PERFECT\n";
        }
    }

    return 0;
}
