// Solve 2023-08-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    int cnt = 0, cnt2 = 0;

    for (int row = 0; row < h; row++) {
        bool inner_area = false;

        for (int col = 0; col < w; col++) {
            char ch;
            cin >> ch;

            if (ch == '.') {
                if (inner_area) cnt++;
            }
            else {
                cnt2++;
                inner_area = !inner_area;
            }
        }
    }

    cout << cnt + cnt2 / 2 << '\n';

    return 0;
}
