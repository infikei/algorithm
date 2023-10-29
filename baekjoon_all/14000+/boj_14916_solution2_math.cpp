// Solve 2022-07-26
// Update 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[15] = { 0, -1, 1, -1, 2, 1, 3, 2, 4, 3, 2, 4, 3, 5, 4 };

    int n, ans;
    cin >> n;

    if (n >= 15) {
        if (n % 5 < 5) {
            ans = arr[n % 5 + 10] + n / 5 - 2;
        }
        else {
            ans = arr[n % 5] + n / 5;
        }
    }
    else {
        ans = arr[n];
    }

    cout << ans << '\n';

    return 0;
}
