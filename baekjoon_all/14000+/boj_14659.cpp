// Solve 2024-03-21

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

    int cur_h = 0;
    int cur_cnt = 0;
    int max_cnt = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (cur_h > h) {
            cur_cnt++;
        }
        else {
            max_cnt = max(max_cnt, cur_cnt);
            cur_h = h;
            cur_cnt = 0;
        }
    }

    max_cnt = max(max_cnt, cur_cnt);

    cout << max_cnt << '\n';

    return 0;
}
