// Solve 2023-09-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw_sign(const Point &a, const Point &b, const Point &c) {
    int ccw_val = calc_cross(b - a, c - a);

    if (ccw_val > 0) return 1;
    if (ccw_val < 0) return -1;
    return 0;
}

int calc_dist2(const Point &a, const Point &b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;

    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    Point tri[3];

    for (int i = 0; i < 3; i++) {
        cin >> tri[i];
    }

    if (calc_ccw_sign(tri[0], tri[1], tri[2]) == 0) {
        cout << "X\n";
    }
    else {
        int tri_len2[3];

        for (int i = 0; i < 3; i++) {
            int ii = i + 1;
            if (ii == 3) ii = 0;

            tri_len2[i] = calc_dist2(tri[i], tri[ii]);
        }

        sort(tri_len2, tri_len2 + 3);

        if (tri_len2[0] == tri_len2[2]) {
            cout << "JungTriangle\n";
        }
        else if (tri_len2[0] == tri_len2[1] || tri_len2[1] == tri_len2[2]) {
            if (tri_len2[0] + tri_len2[1] < tri_len2[2]) {
                cout << "Dunkak2Triangle\n";
            }
            else if (tri_len2[0] + tri_len2[1] > tri_len2[2]) {
                cout << "Yeahkak2Triangle\n";
            }
            else {
                cout << "Jikkak2Triangle\n";
            }
        }
        else {
            if (tri_len2[0] + tri_len2[1] < tri_len2[2]) {
                cout << "DunkakTriangle\n";
            }
            else if (tri_len2[0] + tri_len2[1] > tri_len2[2]) {
                cout << "YeahkakTriangle\n";
            }
            else {
                cout << "JikkakTriangle\n";
            }
        }
    }

    return 0;
}
