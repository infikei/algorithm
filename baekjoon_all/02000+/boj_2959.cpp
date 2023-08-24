// Solve 2022-10-29
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[4];

    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 4);

    int ans = arr[0] * arr[2];

    cout << ans << '\n';

    return 0;
}
