// Solve 2023-02-04
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Area{
    int x0, x1, y0, y1;

    Area(int x0, int x1, int y0, int y1) : x0(x0), x1(x1), y0(y0), y1(y1) {}
};

Area square_min_max(vector<string> &latte, Area area, char ch) {
    int x_min = area.x1, x_max = area.x0;
    int y_min = area.y1, y_max = area.y0;

    for (int x = area.x0; x <= area.x1; x++) {
        for (int y = area.y0; y <= area.y1; y++) {
            if (latte[x][y] == ch) {
                x_min = min(x_min, x); x_max = max(x_max, x);
                y_min = min(y_min, y); y_max = max(y_max, y);
            }
        }
    }

    return { x_min, x_max, y_min, y_max };
}

bool is_heart(vector<string> &latte) {
    int r = SIZE(latte);
    int c = SIZE(latte[0]);

    Area cream = square_min_max(latte, { 0, r - 1, 0, c - 1 }, '#');

    if (cream.x1 - cream.x0 != cream.y1 - cream.y0) return false;
    if (cream.x1 - cream.x0 < 1) return false;

    Area not_cream = square_min_max(latte, { cream.x0, cream.x1, cream.y0, cream.y1 }, '.');

    if (not_cream.x1 - not_cream.x0 != not_cream.y1 - not_cream.y0) return false;
    if (not_cream.x1 - not_cream.x0 < 0) return false;

    if (cream.x0 != not_cream.x0 && cream.x1 != not_cream.x1) return false;
    if (cream.y0 != not_cream.y0 && cream.y1 != not_cream.y1) return false;

    for (int x = cream.x0; x <= cream.x1; x++) {
        for (int y = cream.y0; y <= cream.y1; y++) {
            if (x >= not_cream.x0 && x <= not_cream.x1 && y >= not_cream.y0 && y <= not_cream.y1) {
                if (latte[x][y] != '.') {
                    return false;
                }
            }
            else {
                if (latte[x][y] != '#') {
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
        int r, c;
        cin >> r >> c;

        vector<string> latte(r);

        for (string &row : latte) {
            cin >> row;
        }

        cout << (is_heart(latte) ? 1 : 0) << '\n';
    }

    return 0;
}
