// Solve 2022-08-19
// Update 2023-12-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool is_prime(int n) {
    if (n == 1) return false;

    for (int i = 2, ie = sqrt(n); i <= ie; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int calc_sum_of_digit_squared(int n) {
    int res = 0;

    while (n > 0) {
        int d = n % 10;
        n /= 10;
        res += d * d;
    }

    return res;
}

bool is_happy(int n) {
    if (n == 1) return true;

    vector<bool> visited(10001, false);
    visited[n] = true;

    while (true) {
        n = calc_sum_of_digit_squared(n);

        if (n == 1) return true;
        if (visited[n]) return false;

        visited[n] = true;
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int tii, n;
        cin >> tii >> n;
        cout << tii << ' ' << n << ' ';

        if (is_prime(n) && is_happy(n)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
