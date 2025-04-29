// Solve 2022-07-29
// Update 2025-04-29

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

int arr[1000001];
ll memo[1000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    memo[0]++;

    for (int i = 1; i <= n; i++) {
        arr[i] = (arr[i] + arr[i - 1]) % m;
        memo[arr[i]]++;
    }

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        ans += memo[i] * (memo[i] - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
