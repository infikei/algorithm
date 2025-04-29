// Solve 2023-09-17
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

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n == 1) {
        cout << "YES" << '\n';
        cout << 1 << '\n';
        return 0;
    }

    if (n == 2) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    cout << "1 3 2";

    for (int i = 4; i <= n; i++) {
        cout << ' ' << i;
    }

    cout << '\n';

    return 0;
}
