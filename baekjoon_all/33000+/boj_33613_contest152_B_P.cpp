// Solve 2025-03-16

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

    int n, r, c;
    cin >> n >> r >> c;

    if (n == 2) {
        cout << 1 << '\n';
    }
    else if (n == 3) {
        if (r == 2 && c == 2) {
            cout << 1 << '\n';
        }
        else {
            cout << 4 << '\n';
        }
    }
    else if (n % 2 == 1 && (r + c) % 2 == 0) {
        cout << (ll) n * n / 2 + 1 << '\n';
    }
    else {
        cout << (ll) n * n / 2 << '\n';
    }

    return 0;
}
