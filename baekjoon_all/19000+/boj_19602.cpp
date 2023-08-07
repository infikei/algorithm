// Solve 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ans = 0;

    for (int i = 1; i <= 3; i++) {
        int x;
        cin >> x;

        ans += i * x;
    }

    if (ans >= 10) {
        cout << "happy\n";
    }
    else {
        cout << "sad\n";
    }

    return 0;
}
