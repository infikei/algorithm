// Solve 2024-11-17

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

int rev[8] = {
    0b111000000, 0b000111000, 0b000000111,
    0b100100100, 0b010010010, 0b001001001,
    0b100010001, 0b001010100
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n = 0;

        for (int i = 0; i < 9; i++) {
            char c;
            cin >> c;

            n = n * 2 + (c == 'H' ? 0 : 1);
        }

        int ans = 1000;

        for (int i = 0; i < 256; i++) {
            int cur = n;
            int cnt = 0;

            for (int bi = 0; bi < 8; bi++) {
                if (i & (1 << bi)) {
                    cur ^= rev[bi];
                    cnt++;
                }
            }

            if (cur == 0 || cur == 511) {
                ans = min(ans, cnt);
            }
        }

        println(ans == 1000 ? -1 : ans);
    }

    return 0;
}
