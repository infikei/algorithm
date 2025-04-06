// Solve 2025-04-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int arr[101];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    int ans = -1000000000;

    for (int i = k; i <= n; i++) {
        ans = max(ans, arr[i] - arr[i - k]);
    }

    cout << ans << '\n';

    return 0;
}
