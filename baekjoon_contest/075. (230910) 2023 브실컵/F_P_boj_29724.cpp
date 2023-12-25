// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int weight_sum = 0, apple_cnt_sum = 0;

    for (int i = 0; i < n; i++) {
        char t;
        int w, h, l;
        cin >> t >> w >> h >> l;

        if (t == 'A') {
            int apple_cnt = (w / 12) * (h / 12) * (l / 12);

            apple_cnt_sum += apple_cnt;
            weight_sum += apple_cnt * 500 + 1000;
        }
        else {
            weight_sum += 6000;
        }
    }

    cout << weight_sum << '\n' << apple_cnt_sum * 4000 << '\n';

    return 0;
}
