// Solve 2023-01-25
// Update 2024-11-02

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

    int t;
    cin >> t;

    while (t-- > 0) {
        ll x, y;
        cin >> x >> y;

        ll dist = y - x;
        ll cnt_low = -1;
        ll cnt_high = 100000;

        while (cnt_low + 1 < cnt_high) {
            ll cnt_mid = (cnt_low + cnt_high) / 2;
            ll max_dist = 0;

            if (cnt_mid % 2 == 0) {
                max_dist = (cnt_mid / 2) * (cnt_mid / 2 + 1);
            }
            else {
                max_dist = (cnt_mid / 2 + 1) * (cnt_mid / 2 + 1);
            }

            if (max_dist >= dist) {
                cnt_high = cnt_mid;
            }
            else {
                cnt_low = cnt_mid;
            }
        }

        println(cnt_high);
    }

    return 0;
}
