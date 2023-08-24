// Solve 2022-09-15
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    FASTIO

    int m, d;
    cin >> d >> m;

    for (int i = 0, ie = m - 1; i < ie; i++) {
        d += days[i];
    }

    if (d % 7 == 0) cout << "Wednesday\n";
    else if (d % 7 == 1) cout << "Thursday\n";
    else if (d % 7 == 2) cout << "Friday\n";
    else if (d % 7 == 3) cout << "Saturday\n";
    else if (d % 7 == 4) cout << "Sunday\n";
    else if (d % 7 == 5) cout << "Monday\n";
    else cout << "Tuesday\n";

    return 0;
}
