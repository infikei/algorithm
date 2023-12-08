// Solve 2023-12-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, b1, b2;
    cin >> n >> b1 >> b2;

    bool ans = false;

    for (int i = 0; i < n; i++) {
        int lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;

        if (lx <= b1 && b1 <= hx && ly <= b2 && b2 <= hy) {
            ans = true;
        }
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
