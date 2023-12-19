// Solve 2022-08-12
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Ball{
    int index, color, size;

    Ball(int i, int c, int s) : index(i), color(c), size(s) {}
};

bool cmp_size(const Ball &a, const Ball &b) {
    return a.size < b.size;
}

bool cmp_color_size(const Ball &a, const Ball &b) {
    if (a.color != b.color) {
        return a.color < b.color;
    }

    return a.size < b.size;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Ball> balls;

    for (int i = 1; i <= n; i++) {
        int c, s;
        cin >> c >> s;

        balls.emplace_back(i, c, s);
    }

    sort(balls.begin(), balls.end(), cmp_size);
    vector<int> ans(n + 1, 0);
    int prev_size_sum = 0;
    int duplicate_cnt = 0;

    for (int i = 0; i < n; i++) {
        Ball now_ball = balls[i];

        if (i > 0 && now_ball.size == balls[i - 1].size) {
            duplicate_cnt++;
        }
        else {
            duplicate_cnt = 0;
        }

        ans[now_ball.index] = prev_size_sum - now_ball.size * duplicate_cnt;
        prev_size_sum += now_ball.size;
    }

    sort(balls.begin(), balls.end(), cmp_color_size);
    prev_size_sum = 0;
    duplicate_cnt = 0;

    for (int i = 0; i < n; i++) {
        Ball now_ball = balls[i];

        if (i > 0 && now_ball.color != balls[i - 1].color) {
            prev_size_sum = 0;
            duplicate_cnt = 0;
        }
        else {
            if (i > 0 && now_ball.size == balls[i - 1].size) {
                duplicate_cnt++;
            }
            else {
                duplicate_cnt = 0;
            }
        }

        ans[now_ball.index] -= prev_size_sum - duplicate_cnt * now_ball.size;
        prev_size_sum += now_ball.size;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
