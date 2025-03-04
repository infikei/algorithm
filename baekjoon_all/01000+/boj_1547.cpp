// Solve 2022-11-03
// Update 2025-03-04

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

    int m;
    cin >> m;

    int cur = 1;

    while (m-- > 0) {
        int x, y;
        cin >> x >> y;

        if (x == cur) {
            cur = y;
        }
        else if (y == cur) {
            cur = x;
        }
    }

    cout << cur << '\n';

    return 0;
}
