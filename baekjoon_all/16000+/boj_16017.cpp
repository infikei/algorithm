// Solve 2023-08-11
// Update 2025-03-09

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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a >= 8 && b == c && d >= 8) {
        cout << "ignore" << '\n';
    }
    else {
        cout << "answer" << '\n';
    }

    return 0;
}
