// Solve 2022-11-06
// Update 2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, b;
    cin >> n >> b;

    string ans;

    while (n > 0) {
        int r = n % b;

        if (r > 9) {
            ans = (char)('A' + r - 10) + ans;
        }
        else {
            ans = (char)('0' + r) + ans;
        }

        n /= b;
    }

    cout << ans << '\n';

    return 0;
}
