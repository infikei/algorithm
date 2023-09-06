// Solve 2022-08-04
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x = 0, y = 0;
    bool operator<(const Point &rhs) const {
        if (y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

ostream& operator<<(ostream &os, const Point &rhs) {
    return os << rhs.x << ' ' << rhs.y;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> vec(n);

    for (Point &p : vec) {
        cin >> p;
    }

    sort(vec.begin(), vec.end());

    for (const Point &p : vec) {
        cout << p << '\n';
    }

    return 0;
}
