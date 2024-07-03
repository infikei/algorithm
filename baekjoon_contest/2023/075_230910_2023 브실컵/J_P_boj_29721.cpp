// Solve 2023-09-10
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x = 0, y = 0;
};

int main() {
    FASTIO;

    int dx[4] = { -2, 2, 0, 0 };
    int dy[4] = { 0, 0, -2, 2 };

    int n, k;
    cin >> n >> k;

    vector<Point> points(k);
    set<ll> st;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        points[i].x = x;
        points[i].y = y;
        st.insert((x - 1) * 100000ll + y - 1);
    }

    set<ll> ans_st;

    for (Point &p : points) {
        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

            ll val = (nx - 1) * 100000ll + ny - 1;

            if (st.find(val) == st.end()) {
                ans_st.insert(val);
            }
        }
    }

    cout << SIZE(ans_st) << '\n';

    return 0;
}
