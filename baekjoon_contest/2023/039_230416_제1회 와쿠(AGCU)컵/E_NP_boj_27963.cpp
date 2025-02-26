// Solve 2023-06-29
// Update 2025-02-26

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

    int d1, d2, x;
    cin >> d1 >> d2 >> x;

    if (d1 < d2) {
        swap(d1, d2);
    }

    double density = (double) (100 * d1 * d2) / (d2 * x + d1 * (100 - x));

    SETP(14);
    cout << density << '\n';

    return 0;
}
