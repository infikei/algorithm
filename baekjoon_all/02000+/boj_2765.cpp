// Solve 2023-10-02

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

    SETPRECISION(2);

    double diameter, sec;
    int revolution, ti = 0;

    while (true) {
        cin >> diameter >> revolution >> sec;

        if (revolution == 0) break;

        double distance = diameter * PI * revolution / 63360;
        double mph = distance * 3600 / sec;

        cout << "Trip #" << ++ti << ": " << distance << ' ' << mph << '\n';
    }

    return 0;
}
