// Solve 2025-04-19

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

int memo[11];

int main() {
    FASTIO;

    int h, y;
    cin >> h >> y;

    memo[0] = h;

    for (int i = 1; i <= y; i++) {
        memo[i] = memo[i - 1] * 105 / 100;

        if (i >= 3) {
            memo[i] = max(memo[i], memo[i - 3] * 120 / 100);
        }

        if (i >= 5) {
            memo[i] = max(memo[i], memo[i - 5] * 135 / 100);
        }
    }

    cout << memo[y] << '\n';

    return 0;
}
