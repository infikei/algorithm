// Solve 2023-08-27

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

    for (int ti = 1; ti <= t; ti++) {
        int a[3];

        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }

        sort(a, a + 3);

        cout << "Case #" << ti << ": ";

        if (a[0] + a[1] <= a[2]) {
            cout << "invalid!\n";
        }
        else if (a[0] == a[2]) {
            cout << "equilateral\n";
        }
        else if (a[0] == a[1] || a[1] == a[2]) {
            cout << "isosceles\n";
        }
        else {
            cout << "scalene\n";
        }
    }

    return 0;
}
