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

    int p, q;
    cin >> p >> q;

    vector<int> factor_of_p;

    for (int i = 1, ie = sqrt(p); i <= ie; i++) {
        if (p % i == 0) {
            int ii = p / i;
            factor_of_p.push_back(i);

            if (ii != i) factor_of_p.push_back(ii);
        }
    }

    sort(factor_of_p.begin(), factor_of_p.end());

    vector<int> factor_of_q;

    for (int i = 1, ie = sqrt(q); i <= ie; i++) {
        if (q % i == 0) {
            int ii = q / i;
            factor_of_q.push_back(i);

            if (ii != i) factor_of_q.push_back(ii);
        }
    }

    sort(factor_of_q.begin(), factor_of_q.end());

    for (int &x : factor_of_p) {
        for (int &y : factor_of_q) {
            cout << x << ' ' << y << '\n';
        }
    }

    return 0;
}
