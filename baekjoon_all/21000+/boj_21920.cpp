// Solve 2022-08-03
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int a[500000];

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

bool is_disjoint(int a, int b) {
    return calc_gcd(a, b) == 1;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    int cnt = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        if (is_disjoint(x, a[i])) {
            cnt++;
            sum += a[i];
        }
    }

    SETPRECISION(9);

    double avr = (double)sum / cnt;

    cout << avr << '\n';

    return 0;
}
