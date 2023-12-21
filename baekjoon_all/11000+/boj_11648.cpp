// Solve 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string n;
    cin >> n;

    int ans = 0;

    while (SIZE(n) > 1) {
        int digit_prod = 1;

        for (char d : n) {
            digit_prod *= d - '0';
        }

        n = to_string(digit_prod);
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
