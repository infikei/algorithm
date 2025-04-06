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

int m[200001];
int coke[200001];

int main() {
    FASTIO;

    int n, k, l;
    cin >> n >> k >> l;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    sort(m + 1, m + (n + 1));

    for (int i = 0; i < k; i++) {
        int ti;
        cin >> ti;

        coke[ti]++;

        if (ti + l <= n) coke[ti + l]--;
    }

    for (int i = 1; i <= n; i++) {
        coke[i] += coke[i - 1];
    }

    sort(coke + 1, coke + (n + 1));

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (coke[i] <= 30) ans += (m[i] >> coke[i]);
    }

    cout << ans << '\n';

    return 0;
}
