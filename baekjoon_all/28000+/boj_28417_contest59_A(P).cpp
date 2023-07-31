// Solve 2023-07-29

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

    int arr[7], ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> arr[j];
        }

        sort(arr, arr + 2);
        sort(arr + 2, arr + 7);

        ans = max(ans, arr[1] + arr[5] + arr[6]);
    }

    cout << ans << '\n';

    return 0;
}
