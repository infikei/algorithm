// Solve 2022-07-30
// Update 2024-02-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, r, c;
    cin >> n >> r >> c;

    int cur_depth = n;
    int cur_num = 0;

    while (--cur_depth >= 0) {
        int sub_area = 1 << (cur_depth * 2);

        if (r >= (1 << cur_depth)) {
            cur_num += sub_area * 2;
            r -= 1 << cur_depth;
        }

        if (c >= (1 << cur_depth)) {
            cur_num += sub_area;
            c -= 1 << cur_depth;
        }
    }

    cout << cur_num << '\n';

    return 0;
}
