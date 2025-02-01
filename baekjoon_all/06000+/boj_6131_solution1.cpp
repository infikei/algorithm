// Solve 2023-03-08
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 0;

    for (int a = 1; a <= 500; a++) {
        int a2 = a * a;

        for (int b = 1; b <= a; b++) {
            int b2 = b * b;

            if (a2 == b2 + n) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
