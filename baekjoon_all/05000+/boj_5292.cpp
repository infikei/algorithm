// Solve 2023-10-06

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

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            if (i % 5 == 0) {
                cout << "DeadMan\n";
            }
            else {
                cout << "Dead\n";
            }
        }
        else {
            if (i % 5 == 0) {
                cout << "Man\n";
            }
            else {
                cout << i << ' ';
            }
        }
    }

    return 0;
}
