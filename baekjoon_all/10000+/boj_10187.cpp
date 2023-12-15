// Solve 2023-12-15

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

    double golden_ratio = (1 + sqrt(5)) * 0.5;
    double golden_ratio_lower_bound = golden_ratio * 0.99;
    double golden_ratio_upper_bound = golden_ratio * 1.01;

    for (int i = 0; i < n; i++) {
        double p, q;
        cin >> p >> q;

        if (p < q) swap(p, q);

        double ratio = p / q;

        if (golden_ratio_lower_bound <= ratio && ratio <= golden_ratio_upper_bound) {
            cout << "golden\n";
        }
        else {
            cout << "not\n";
        }
    }

    return 0;
}
