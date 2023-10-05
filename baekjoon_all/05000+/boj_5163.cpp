// Solve 2023-10-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int b;
        double weight;
        cin >> b >> weight;

        double volume = 0;

        for (int bi = 0; bi < b; bi++) {
            double radius;
            cin >> radius;

            volume += radius * radius * radius * PI * 4 / 3;
        }

        volume *= 0.001;

        if (ti >= 2) cout << '\n';

        if (volume > weight) {
            cout << "Data Set " << ti << ":\nYes\n";
        }
        else {
            cout << "Data Set " << ti << ":\nNo\n";
        }
    }

    return 0;
}
