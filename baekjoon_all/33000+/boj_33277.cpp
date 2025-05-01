// Solve 2025-04-30

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

    int n, m;
    cin >> n >> m;

    int d = floor((double) (1440 * m) / n);

    SETW(2, '0');
    cout << d / 60 << ':';
    SETW(2, '0');
    cout << d % 60 << '\n';

    return 0;
}
