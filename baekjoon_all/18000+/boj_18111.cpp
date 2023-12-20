// Solve 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, b;
    cin >> n >> m >> b;

    vector<int> block_cnt(257, 0);

    for (int i = 0, ie = n * m; i < ie; i++) {
        int x;
        cin >> x;

        block_cnt[x]++;
    }

    int time_min = 500 * 500 * 256 * 2;
    int height_ans = 0;

    for (int height = 0; height <= 256; height++) {
        int higher_cnt = 0; // 블록을 놓아야 하는 횟수
        int lower_cnt = 0; // 블록을 제거해야 하는 횟수

        for (int h = 0; h < height; h++) {
            higher_cnt += block_cnt[h] * (height - h);
        }

        for (int h = height + 1; h <= 256; h++) {
            lower_cnt += block_cnt[h] * (h - height);
        }

        // 기존에 가지고 있는 블록의 개수와 제거해야 하는 블록의 개수의 총합이
        // 놓아야 하는 블록의 개수 이상이어야 한다.
        if (b + lower_cnt >= higher_cnt) {
            int time = lower_cnt * 2 + higher_cnt;

            if (time <= time_min) {
                time_min = time;
                height_ans = height;
            }
        }
    }

    cout << time_min << ' ' << height_ans << '\n';

    return 0;
}
