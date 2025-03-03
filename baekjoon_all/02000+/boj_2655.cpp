// Solve 2025-03-03

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

struct Brick{
    int num, s, h, w;
    int sum_h, prev_idx;

    bool operator<(const Brick &rhs) const {
        return s < rhs.s;
    }
};

Brick bricks[101];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        bricks[i].num = i + 1;
        cin >> bricks[i].s >> bricks[i].h >> bricks[i].w;
    }

    sort(bricks, bricks + n);

    for (int i = 0; i < n; i++) {
        int max_sum_h = -1;
        int prev_idx = -1;

        for (int j = 0; j < i; j++) {
            if (bricks[j].w < bricks[i].w && bricks[j].sum_h > max_sum_h) {
                max_sum_h = bricks[j].sum_h;
                prev_idx = j;
            }
        }

        if (prev_idx == -1) {
            bricks[i].sum_h = bricks[i].h;
            bricks[i].prev_idx = -1;
        }
        else {
            bricks[i].sum_h = bricks[i].h + max_sum_h;
            bricks[i].prev_idx = prev_idx;
        }
    }

    int max_sum_h = 0;
    int idx_of_max_sum_h = 0;

    for (int i = 0; i < n; i++) {
        if (bricks[i].sum_h > max_sum_h) {
            max_sum_h = bricks[i].sum_h;
            idx_of_max_sum_h = i;
        }
    }

    stack<int> stck;
    int cur_idx = idx_of_max_sum_h;

    while (cur_idx != -1) {
        stck.push(bricks[cur_idx].num);
        cur_idx = bricks[cur_idx].prev_idx;
    }

    cout << SIZE(stck) << '\n';

    while (!stck.empty()) {
        cout << stck.top() << '\n';
        stck.pop();
    }

    return 0;
}
