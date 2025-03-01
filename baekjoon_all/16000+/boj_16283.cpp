// Solve 2025-02-28

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

    int a, b, n, w;
    cin >> a >> b >> n >> w;

    int possible_cnt = 0;
    int sheep = 0;
    int goat = 0;

    for (int x = 1; x < n; x++) {
        if (a * x + b * (n - x) == w) {
            possible_cnt++;
            sheep = x;
            goat = n - x;

            if (possible_cnt >= 2) break;
        }
    }

    if (possible_cnt == 1) {
        cout << sheep << ' ' << goat << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
