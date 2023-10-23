// Solve 2023-10-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        if (ti >= 1) cout << '\n';

        int n;
        cin >> n;

        int sum_of_proper_divisors = 0;

        for (int i = 1, ie = sqrt(n); i <= ie; i++) {
            if (n % i != 0) continue;

            sum_of_proper_divisors += i;

            int ii = n / i;

            if (ii != i) sum_of_proper_divisors += ii;
        }

        sum_of_proper_divisors -= n;

        if (sum_of_proper_divisors < n) {
            cout << n << " is a deficient number.\n";
        }
        else if (sum_of_proper_divisors > n) {
            cout << n << " is an abundant number.\n";
        }
        else {
            cout << n << " is a perfect number.\n";
        }
    }

    return 0;
}
