// Solve 2023-07-09

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

    if (n & 1) {
        cout << 0 << '\n';
    }
    else {
        int b = 3, s = 4;

        for (int i = 1, i_end = (n >> 1); i < i_end; i++) {
            b += s << 1;
            s += b;
        }

        cout << b << '\n';
    }

    return 0;
}
