// Solve 2025-06-02

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

    int x, n;
    cin >> x >> n;

    if (n == 0) {
        if (0 < x) cout << "INFINITE" << '\n';
        else cout << 0 << '\n';
    }
    else if (n == 1) {
        if (0 < -x) cout << "INFINITE" << '\n';
        else cout << 0 << '\n';
    }
    else if (n % 2 == 0) {
        cout << max((x - 1) / (n / 2), 0) << '\n';
    }
    else {
        cout << "ERROR" << '\n';
    }

    return 0;
}
