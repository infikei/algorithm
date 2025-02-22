// Solve 2023-07-29
// Update 2025-02-21

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll sum[2] = { 0 };

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        sum[i & 1] += x;
    }

    if (n == 3 && sum[1] > sum[0]) {
        cout << -1 << '\n';
    }
    else {
        cout << abs(sum[0] - sum[1]) << '\n';
    }

    return 0;
}
