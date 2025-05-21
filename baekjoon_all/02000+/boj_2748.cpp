// Solve 2022-07-09
// Update 2025-05-18

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

    ll fibonacci[91] = { 0, 1 };

    for (int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }

    cout << fibonacci[n] << '\n';

    return 0;
}
