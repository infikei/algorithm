// Solve 2025-06-07

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

    cout << n * 2 - 1 << '\n';

    int cur = 1;

    for (int i = 1; i < n; i++) {
        cout << cur << ' ' << cur + n - 1 << ' ' << i << ' ' << 1 << '\n';
        cout << cur + n << ' ' << cur + n << ' ' << n << ' ' << i + 1 << '\n';
        cur += n + 1;
    }

    cout << cur << ' ' << cur << ' ' << n << ' ' << 1 << '\n';
    return 0;
}
