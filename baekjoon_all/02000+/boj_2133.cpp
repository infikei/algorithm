// Solve 2023-07-09
// Update 2023-07-26

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
        int a = 3, s = 4;

        int i = 1, i_end = n >> 1;
        while (i < i_end) {
            a += s << 1; // a_n = a_(n-1) + 2 * S_(n-1)
            s += a; // S_n = S_(n-1) + a_n
            i++;
        }

        cout << a << '\n';
    }

    return 0;
}
