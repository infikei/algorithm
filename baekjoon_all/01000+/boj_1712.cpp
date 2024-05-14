// Solve 2024-05-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c;
    cin >> a >> b >> c;

    if (b >= c) {
        cout << -1 << '\n';
    }
    else {
        cout << (int) (a / (c - b)) + 1;
    }

    return 0;
}
