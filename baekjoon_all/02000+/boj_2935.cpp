// Solve 2022-10-31
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+') {
        if (SIZE(a) >= SIZE(b)) {
            a[SIZE(a) - SIZE(b)]++;
            cout << a << '\n';
        }
        else {
            b[SIZE(b) - SIZE(a)]++;
            cout << b << '\n';
        }
    }
    else {
        cout << a << b.substr(1, SIZE(b) - 1) << '\n';
    }

    return 0;
}
