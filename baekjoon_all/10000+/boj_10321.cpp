// Solve 2024-05-04
// Update 2024-05-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int n;
Point points[1000];

int get_ccw(const Point &p1, const Point &p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int get_ccw(const Point &p1, const Point &p2, const Point &p3) {
    return get_ccw(p2 - p1, p3 - p1);
}

struct PointCmpCcwXY{
    bool operator()(Point &p1, Point &p2) {
        int ccw = get_ccw(points[0], p1, p2);

        if (ccw != 0) return ccw > 0;
        return p1 < p2;
    }
};

vector<Point> make_convex_hull() {
    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, PointCmpCcwXY());
    vector<Point> convex_hull;

    for (int i = 0; i < n; i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back = convex_hull.back();
            convex_hull.pop_back();

            if (get_ccw(convex_hull.back(), back, points[i]) > 0) {
                convex_hull.push_back(back);
                break;
            }
        }

        convex_hull.push_back(points[i]);
    }

    return convex_hull;
}

int get_area2(vector<Point> &convex_hull) {
    int area = 0;

    for (int i = 2; i < SIZE(convex_hull); i++) {
        area += get_ccw(convex_hull[0], convex_hull[i - 1], convex_hull[i]);
    }

    return area;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        vector<Point> convex_hull = make_convex_hull();
        int ch_size = SIZE(convex_hull);
        int max_area2 = 0;

        if (ch_size >= 4) {
            for (int i = 0; i < ch_size; i++) {
                for (int j = 2; j <= ch_size - 2; j++) {
                    int j_idx = (i + j) % ch_size;

                    int low = 0;
                    int high = j;

                    while (low + 2 < high) {
                        int mid1 = ((low << 1) + high) / 3;
                        int mid2 = (low + (high << 1)) / 3;

                        int mid1_idx = (i + mid1) % ch_size;
                        int mid2_idx = (i + mid2) % ch_size;

                        int mid1_ccw = get_ccw(convex_hull[i], convex_hull[mid1_idx], convex_hull[j_idx]);
                        int mid2_ccw = get_ccw(convex_hull[i], convex_hull[mid2_idx], convex_hull[j_idx]);

                        if (mid1_ccw < mid2_ccw) {
                            low = mid1;
                        }
                        else {
                            high = mid2;
                        }
                    }

                    int far1 = low;
                    int far1_idx = (i + low) % ch_size;
                    int far1_ccw = 0;

                    for (int cur = low; cur <= high; cur++) {
                        int cur_idx = (i + cur) % ch_size;
                        int cur_ccw = get_ccw(convex_hull[i], convex_hull[cur_idx], convex_hull[j_idx]);

                        if (cur_ccw > far1_ccw) {
                            far1_ccw = cur_ccw;
                            far1_idx = cur_idx;
                            far1 = cur;
                        }
                    }

                    low = j;
                    high = ch_size;

                    while (low + 2 < high) {
                        int mid1 = ((low << 1) + high) / 3;
                        int mid2 = (low + (high << 1)) / 3;

                        int mid1_idx = (i + mid1) % ch_size;
                        int mid2_idx = (i + mid2) % ch_size;

                        int mid1_ccw = get_ccw(convex_hull[j_idx], convex_hull[mid1_idx], convex_hull[i]);
                        int mid2_ccw = get_ccw(convex_hull[j_idx], convex_hull[mid2_idx], convex_hull[i]);

                        if (mid1_ccw < mid2_ccw) {
                            low = mid1;
                        }
                        else {
                            high = mid2;
                        }
                    }

                    int far2 = low;
                    int far2_idx = (i + low) % ch_size;
                    int far2_ccw = 0;

                    for (int cur = low; cur <= high; cur++) {
                        int cur_idx = (i + cur) % ch_size;
                        int cur_ccw = get_ccw(convex_hull[j_idx], convex_hull[cur_idx], convex_hull[i]);

                        if (cur_ccw > far2_ccw) {
                            far2_ccw = cur_ccw;
                            far2_idx = cur_idx;
                            far2 = cur;
                        }
                    }

                    vector<Point> cur_square;
                    cur_square.push_back(convex_hull[i]);
                    cur_square.push_back(convex_hull[far1_idx]);
                    cur_square.push_back(convex_hull[j_idx]);
                    cur_square.push_back(convex_hull[far2_idx]);

                    int cur_area2 = get_area2(cur_square);
                    max_area2 = cur_area2 > max_area2 ? cur_area2 : max_area2;
                }
            }
        }
        else {
            max_area2 = get_area2(convex_hull);
        }

        cout << max_area2 / 2 << (max_area2 % 2 != 0 ? ".5" : "") << '\n';
    }

    return 0;
}
