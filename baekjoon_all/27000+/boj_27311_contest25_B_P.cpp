#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pi4 = pair<pii, pii>;

int r, c;
string latte[10];

pi4 square_min_max(pi4 area, char ch) {
    int r0 = area.first.first, r1 = area.first.second;
    int c0 = area.second.first, c1 = area.second.second;

    int r_min = r1, r_max = r0;
    int c_min = c1, c_max = c0;
    for (int row = r0; row <= r1; row++) {
        for (int col = c0; col <= c1; col++) {
            if (latte[row][col] == ch) {
                r_min = min(r_min, row); r_max = max(r_max, row);
                c_min = min(c_min, col); c_max = max(c_max, col);
            }
        }
    }
    return {{r_min, r_max}, {c_min, c_max}};
}

bool is_heart() {
    pi4 area_n = square_min_max({{0, r - 1}, {0, c - 1}}, '#');
    int r0 = area_n.first.first, r1 = area_n.first.second;
    int c0 = area_n.second.first, c1 = area_n.second.second;
    if (r1 - r0 != c1 - c0 || r1 - r0 < 1) {
        return false;
    }

    pi4 area_m = square_min_max({{r0, r1}, {c0, c1}}, '.');
    int r2 = area_m.first.first, r3 = area_m.first.second;
    int c2 = area_m.second.first, c3 = area_m.second.second;
    if (r3 - r2 != c3 - c2 || r3 - r2 < 0) {
        return false;
    }
    if ((r0 != r2 && r1 != r3) || (c0 != c2 && c1 != c3)) {
        return false;
    }

    for (int row = r0; row <= r1; row++) {
        for (int col = c0; col <= c1; col++) {
            if (row >= r2 && row <= r3 && col >= c2 && col <= c3) {
                if (latte[row][col] != '.') {
                    return false;
                }
            }
            else {
                if (latte[row][col] != '#') {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        cin >> r >> c;
        for (int row = 0; row < r; row++) {
            cin >> latte[row];
        }
        cout << (is_heart() ? 1 : 0) << '\n';
    }

    return 0;
}