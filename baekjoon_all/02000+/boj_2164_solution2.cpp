// Solve 2022-06-05
// Update 2024-02-02

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

    if (n == 1) {
        cout << 1 << '\n';
    }
    else {
        int pow = 1;

        while (true) {
            if (n <= (pow <<= 1)) break;
        }

        // cout << pow - (pow - n) * 2 << '\n';
        cout << n * 2 - pow << '\n';
    }

    return 0;
}
