// Solve 2023-09-03
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    int n, p;
    cin >> n >> p;

    int pp = 100;

    for (int i = 0; i < p; i++) {
        pp *= 10;
    }

    int per[100];
    int cnt[100];
    int gcd = pp;

    for (int ni = 0; ni < n; ni++) {
        cin >> per[ni];

        gcd = calc_gcd(per[ni], gcd);
    }

    for (int ni = 0; ni < n; ni++) {
        cnt[ni] = per[ni] / gcd;
    }

    int nper[100];
    int ncnt[100];
    int ngcd = pp;
    int mult = 1;

    for (int ni = 0; ni < n; ni++) {
        cin >> nper[ni];

        ngcd = calc_gcd(nper[ni], ngcd);
    }

    for (int ni = 0; ni < n; ni++) {
        ncnt[ni] = nper[ni] / ngcd;

        if (ncnt[ni] > 0) {
            mult = max(mult, (cnt[ni] - 1) / ncnt[ni] + 1);
        }
    }

    cout << pp / gcd << ' ' << pp / ngcd * (ll)mult << '\n';

    return 0;
}
