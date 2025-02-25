// Solve 2022-06-30
// Update 2025-02-25

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

    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;

    int x_cost = a * p;
    int y_cost = b + max(0, p - c) * d;

    cout << min(x_cost, y_cost) << '\n';

    return 0;
}
