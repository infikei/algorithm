// Solve 2024-10-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int r_low = 0; // true
    int r_high = 40; // false

    while (r_low + 1 < r_high) {
        int r_mid = (r_low + r_high) / 2;

        if (r_mid * (r_mid + 1) <= n) {
            r_low = r_mid;
        }
        else {
            r_high = r_mid;
        }
    }

    int x = (r_low % 2 == 1 ? r_low / 2 + 1 : -r_low / 2);
    int y = x;
    int moved_cnt = r_low * (r_low + 1);
    int extra_move_cnt = n - moved_cnt;

    if (r_low % 2 == 1) {
        y -= min(extra_move_cnt, r_low + 1);
    }
    else {
        y += min(extra_move_cnt, r_low + 1);
    }

    extra_move_cnt -= r_low + 1;

    if (extra_move_cnt > 0) {
        if (r_low % 2 == 1) {
            x -= extra_move_cnt;
        }
        else {
            x += extra_move_cnt;
        }
    }

    printw(x); println(y);

    return 0;
}
