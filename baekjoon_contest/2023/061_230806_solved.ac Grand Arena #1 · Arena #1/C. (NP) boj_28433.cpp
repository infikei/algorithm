// Solve 2023-08-09

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
        int n;
        cin >> n;

        int positive = 0, negative = 0;
        ll prev = 0;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;

            if (x > 0) {
                if (prev <= 0 && prev + x > 0) {
                    prev += x;
                }
                else {
                    if (prev < 0) negative++;
                    else if (prev > 0) positive++;

                    prev = x;
                }
            }
            else if (x < 0) {
                if (prev > 0 && prev + x <= 0) {
                    positive++;
                    prev = x;
                }
                else {
                    prev += x;
                }
            }
        }

        if (prev < 0) negative++;
        else if (prev > 0) positive++;

        if (positive > negative) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
