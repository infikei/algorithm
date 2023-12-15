// Solve 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    int cnt = 0;

    while (a != b) {
        int na = abs(a - b);
        int nb = min(a, b);

        a = na;
        b = nb;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
