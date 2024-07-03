// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[200000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        ans2 += arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0, ie = n / 2; i < ie; i++) {
        ans += arr[i];
    }

    ans2 -= ans;

    cout << ans << ' ' << ans2 << '\n';

    return 0;
}
