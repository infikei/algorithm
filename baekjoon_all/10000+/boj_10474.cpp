// Solve 2022-11-23
// Update 2023-12-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        cout << a / b << ' ' << a % b << " / " << b << '\n';
    }

    return 0;
}
