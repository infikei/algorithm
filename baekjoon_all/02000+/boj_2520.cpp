// Solve 2025-03-26

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

    pii batter_quantity[5] = { { 1, 2 }, { 1, 2 }, { 1, 4 }, { 1, 16 }, { 9, 16 } };
    int pancake_quantity[4] = { 1, 30, 25, 10 };

    int t;
    cin >> t;

    while (t-- > 0) {
        int batter_ingredient[5];
        int pancake_ingredient[4];

        for (int i = 0; i < 5; i++) {
            cin >> batter_ingredient[i];
        }

        for (int i = 0; i < 4; i++) {
            cin >> pancake_ingredient[i];
        }

        int batter_cnt = batter_ingredient[0] * batter_quantity[0].second / batter_quantity[0].first;

        for (int i = 0; i < 5; i++) {
            batter_cnt = min(batter_cnt, batter_ingredient[i] * batter_quantity[i].second / batter_quantity[i].first);
        }

        int pancake_cnt = 0;

        for (int i = 0; i < 4; i++) {
            pancake_cnt += pancake_ingredient[i] / pancake_quantity[i];
        }

        pancake_cnt = min(pancake_cnt, batter_cnt);

        cout << pancake_cnt << '\n';
    }

    return 0;
}
