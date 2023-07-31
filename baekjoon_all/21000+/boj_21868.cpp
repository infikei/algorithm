// Solve 2023-07-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ep_q, ep_p, a, b, x0;
    cin >> ep_q >> ep_p >> a >> b >> x0;

    cout << a * x0 + b << '\n';

    if (a == 0) {
        cout << 0 << ' ' << 0 << '\n';
    }
    else {
        cout << ep_q << ' ' << ep_p * abs(a) << '\n';
    }


    return 0;
}
