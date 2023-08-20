// Solve 2023-08-18

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
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    set<Point> st;

    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;

        Point p;

        if (xi == 0) {
            if (yi > 0) p = { 0, 1 };
            else p = { 0, -1 };
        }
        else if (yi == 0) {
            if (xi > 0) p = { 1, 0 };
            else p = { -1, 0 };
        }
        else {
            int gcd = calc_gcd(abs(xi), abs(yi));
            p = { xi / gcd, yi / gcd };
        }

        st.insert(p);
    }

    cout << SIZE(st) << '\n';

    return 0;
}
