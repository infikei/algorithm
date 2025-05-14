// Solve 2025-05-14

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

    int x, y;
    cin >> x >> y;

    if (x > y || y > 2 * x) {
        cout << -1 << '\n';
        return 0;
    }

    cout << 506 * (2 * x - y) << '\n';

    return 0;
}
