// Solve 2023-11-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, x, k;
    cin >> n >> x >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        if (x == a) x = b;
        else if (x == b) x = a;
    }

    cout << x << '\n';

    return 0;
}
