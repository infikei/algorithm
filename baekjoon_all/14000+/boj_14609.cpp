// Solve 2023-08-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

double f(const vector<int> &c, const double x) {
    double res = 0;

    for (const int &ci : c) {
        res *= x;
        res += ci;
    }

    return res;
}

double calc_true_integral(const vector<int> &c, const ll a, const ll b) {
    double res = 0;

    int r = 1;
    ll ar = a, br = b;

    for (auto it = c.rbegin(); it != c.rend(); it++) {
        res += *it * (double)(br - ar) / r;

        ar *= a;
        br *= b;
        r++;
    }

    return res;
}

int main() {
    FASTIO;

    SETPRECISION(9);

    int k;
    cin >> k;

    vector<int> c(k + 1, 0);
    for (int &ci : c) {
        cin >> ci;
    }

    int a, b, n;
    cin >> a >> b >> n;

    double true_integral = calc_true_integral(c, a, b);
    double delta_x = (double)(b - a) / n;

    double eps_low = 0, eps_high = delta_x;

    while (true) {
        double eps_mid = (eps_low + eps_high) / 2;

        double integral = 0;
        for (int k = 0; k < n; k++) {
            integral += f(c, a + k * delta_x + eps_mid);
        }
        integral *= delta_x;

        if (abs(integral - true_integral) < 1e-4) {
            break;
        }

        if (integral < true_integral) {
            eps_low = eps_mid;
        }
        else {
            eps_high = eps_mid;
        }
    }

    cout << (eps_low + eps_high) / 2 << '\n';

    return 0;
}
