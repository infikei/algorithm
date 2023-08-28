// Solve 2022-11-07
// Update 2023-08-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int money[6] = { 500, 100, 50, 10, 5, 1 };

    int x;
    cin >> x;

    x = 1000 - x;

    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        cnt += x / money[i];
        x %= money[i];
    }

    cout << cnt << '\n';

    return 0;
}
