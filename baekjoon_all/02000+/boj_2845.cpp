// Solve 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int l, p;
    cin >> l >> p;
    p *= l;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;

        cout << x - p << ' ';
    }
    cout << '\n';

    return 0;
}
