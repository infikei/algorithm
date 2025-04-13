// Solve 2025-01-26
// Update 2025-04-12

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

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    n /= a;

    int day = 0;

    while (k >= 1) {
        day++;
        k--;

        if (day % n == 0) {
            k += b;
        }
    }

    cout << day << '\n';

    return 0;
}
