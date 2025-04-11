// Solve 2025-04-11

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

struct Point{
    double x, y;

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

double get_dist(const Point &p1, const Point &p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

double get_outer_product(const Point &p1, const Point &p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int main() {
    FASTIO;

    vector<Point> triangle(3);
    vector<double> triangle_length(3);

    while (true) {
        string s;
        cin >> s;

        if (s == "-1") break;

        triangle[0].x = stod(s);
        cin >> triangle[0].y;
        cin >> triangle[1].x >> triangle[1].y;
        cin >> triangle[2].x >> triangle[2].y;

        if (get_outer_product(triangle[1] - triangle[0], triangle[2] - triangle[0]) == 0) {
            cout << "Not a Triangle" << '\n';
            continue;
        }

        triangle_length[0] = get_dist(triangle[0], triangle[1]);
        triangle_length[1] = get_dist(triangle[0], triangle[2]);
        triangle_length[2] = get_dist(triangle[1], triangle[2]);
        sort(triangle_length.begin(), triangle_length.end());

        if (triangle_length[2] <= triangle_length[0] + 0.01) {
            cout << "Equilateral" << ' ';
        }
        else if (triangle_length[1] <= triangle_length[0] + 0.01 || triangle_length[2] <= triangle_length[1] + 0.01) {
            cout << "Isosceles" << ' ';
        }
        else {
            cout << "Scalene" << ' ';
        }

        double degree = (triangle_length[0] * triangle_length[0] + triangle_length[1] * triangle_length[1] - triangle_length[2] * triangle_length[2])
                / (2 * triangle_length[0] * triangle_length[1]);
        degree = acos(degree) * 180.0 / M_PI;

        if (degree >= 89 && degree <= 91) {
            cout << "Right" << '\n';
        }
        else if (degree > 90) {
            cout << "Obtuse" << '\n';
        }
        else {
            cout << "Acute" << '\n';
        }
    }

    return 0;
}
