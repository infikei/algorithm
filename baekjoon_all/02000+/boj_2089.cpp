// Solve 2022-07-13
// Update 2023-09-28

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

    string ans;

    if (n == 0) ans = "0";

    while (n != 0) {
        if (n % 2 == 0) {
            ans.push_back('0');
        }
        else {
            ans.push_back('1');
            n--;
        }

        n /= -2;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
