// Solve 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double a[7] = { 9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193 };
    double b[7] = { 26.7, 75., 1.5, 42.5, 210., 3.8, 254. };
    double c[7] = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88 };
    bool track_field[7] = { true, false, false, true, false, false, true };

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int score_sum = 0;

        for (int i = 0; i < 7; i++) {
            double p;
            cin >> p;

            int score;

            if (track_field[i]) {
                score = a[i] * pow(b[i] - p, c[i]);
            }
            else {
                score = a[i] * pow(p - b[i], c[i]);
            }

            score_sum += score;
        }

        cout << score_sum << '\n';
    }

    return 0;
}
