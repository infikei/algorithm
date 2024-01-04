// Solve 2024-01-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int check[100] = { 0 };

    for (int i = a; i < b; i++) {
        check[i] = 1;
    }

    for (int i = c; i < d; i++) {
        check[i] = 1;
    }

    int cnt = 0;

    for (int i = 0; i < 100; i++) {
        if (check[i]) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
