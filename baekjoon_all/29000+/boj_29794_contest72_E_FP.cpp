// Solve 2023-09-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    int lv_to_cnt[200] = { 0 };

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        lv_to_cnt[h]++;
        if (h + k < 200) lv_to_cnt[h + k]--;
    }

    for (int lv = 1; lv < 200; lv++) {
        lv_to_cnt[lv] += lv_to_cnt[lv - 1];
    }

    int monsters[201];

    for (int fl = 1; fl <= m; fl++) {
        cin >> monsters[fl];
    }

    int lv_to_floor[200] = { 0 };

    for (int lv = 1; lv < 200; lv++) {
        int max_monster = 0;

        for (int fl = 1; fl <= m; fl++) {
            if (monsters[fl] <= lv && max_monster < monsters[fl]) {
                max_monster = monsters[fl];
                lv_to_floor[lv] = fl;
            }
        }
    }

    ll val0 = 0;

    for (int i = 1; i < 200; i++) {
        val0 += (ll)lv_to_cnt[i] * (lv_to_floor[i] - 1);
    }

    ll min_val = val0;
    int min_fl_x = 1, min_fl_y = 2;

    for (int fl_x = 1; fl_x <= m; fl_x++) {
        for (int fl_y = fl_x + 1; fl_y <= m; fl_y++) {
            ll val = 0;

            for (int lv = 1; lv < 200; lv++) {
                val += (ll)lv_to_cnt[lv] * min(lv_to_floor[lv] - 1, fl_x - 1 + abs(lv_to_floor[lv] - fl_y));
            }

            if (val < min_val) {
                min_val = val;
                min_fl_x = fl_x;
                min_fl_y = fl_y;
            }
        }
    }

    cout << min_fl_x << ' ' << min_fl_y << '\n' << val0 - min_val << '\n';

    return 0;
}
