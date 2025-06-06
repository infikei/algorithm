// Solve 2025-06-06

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

    while (true) {
        int x, y;
        cin >> x >> y;

        if (x == 0 && y == 0) break;

        if (x + y == 13) {
            cout << "Never speak again." << '\n';
        }
        else if (x > y) {
            cout << "To the convention." << '\n';
        }
        else if (x < y) {
            cout << "Left beehind." << '\n';
        }
        else {
            cout << "Undecided." << '\n';
        }
    }

    return 0;
}
