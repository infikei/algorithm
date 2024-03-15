// Solve 2024-03-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int len_s;
    string s;
    ll dx, dy;
    cin >> len_s >> s >> dy >> dx;
    dx = -dx;

    ll x = 0;
    ll y = 0;

    for (int i = 0; i < len_s; i++) {
        if (s[i] == '1') {
            y |= 1ll << (len_s - 1 - i);
        }
        else if (s[i] == '3') {
            x |= 1ll << (len_s - 1 - i);
        }
        else if (s[i] == '4') {
            x |= 1ll << (len_s - 1 - i);
            y |= 1ll << (len_s - 1 - i);
        }
    }

    x += dx;
    y += dy;

    if (x < 0ll || x >= (1ll << len_s) || y < 0ll || y >= (1ll << len_s)) {
        cout << -1 << '\n';
    }
    else {
        for (int i = len_s - 1; i >= 0; i--) {
            if (x & 1ll) {
                if (y & 1ll) {
                    s[i] = '4';
                }
                else {
                    s[i] = '3';
                }
            }
            else {
                if (y & 1ll) {
                    s[i] = '1';
                }
                else {
                    s[i] = '2';
                }
            }

            x >>= 1;
            y >>= 1;
        }

        cout << s << '\n';
    }

    return 0;
}
