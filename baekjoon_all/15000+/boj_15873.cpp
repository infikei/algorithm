// Solve 2022-11-01
// Update 2023-11-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a_b;
    cin >> a_b;

    if (SIZE(a_b) == 4) {
        cout << 20 << '\n';
    }
    else if (SIZE(a_b) == 2) {
        cout << (a_b[0] - '0') + (a_b[1] - '0') << '\n';
    }
    else if (a_b[1] == '0') {
        cout << a_b[0] << a_b[2] << '\n';
    }
    else {
        cout << a_b[1] << a_b[0] << '\n';
    }

    return 0;
}
