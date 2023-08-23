// Solve 2022-10-15
// Update 2023-08-23

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

    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;

        if (x % n == 0) {
            cout << x << " is a multiple of " << n << ".\n";
        }
        else {
            cout << x << " is NOT a multiple of " << n << ".\n";
        }
    }

    return 0;
}
