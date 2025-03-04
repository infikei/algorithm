// Solve 2022-07-23
// Update 2025-03-04

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

    string line;
    cin >> line;

    int ans = 0;
    int tmp = 0;
    bool minus = false;

    for (char &c : line) {
        if (c == '+' || c == '-') {
            if (minus) {
                ans -= tmp;
            }
            else {
                ans += tmp;
            }

            tmp = 0;

            if (c == '-') {
                minus = true;
            }
        }
        else {
            tmp = tmp * 10 + (c - '0');
        }
    }

    if (minus) {
        ans -= tmp;
    }
    else {
        ans += tmp;
    }

    cout << ans << '\n';

    return 0;
}
