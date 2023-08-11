// Solve 2023-08-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        char ch;
        cin >> ch;

        if (ch == 'W') cnt++;
    }

    if (cnt >= 5) cout << 1 << '\n';
    else if (cnt >= 3) cout << 2 << '\n';
    else if (cnt >= 1) cout << 3 << '\n';
    else cout << -1 << '\n';

    return 0;
}
