// Solve 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<ll> esc = { -1, 1, 1 };

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        vector<ll> new_esc(3);

        new_esc[0] = esc[0] - esc[2];
        new_esc[1] = esc[1] + esc[2];
        new_esc[2] = (esc[0] - esc[1]) * 2 + esc[2];

        swap(esc, new_esc);
    }

    cout << esc[0] + esc[1] + esc[2] << '\n';

    return 0;
}
