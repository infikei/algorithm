// Solve 2025-04-15
// Update 2025-10-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points;
    vector<int> x_list;
    vector<int> y_list;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x, y);
        x_list.push_back(x);
        y_list.push_back(y);
    }

    sort(x_list.begin(), x_list.end());
    sort(y_list.begin(), y_list.end());
    vector<int> dist_sum_min(n, INF);

    for (int x : x_list) {
        for (int y : y_list) {
            vector<int> dist;

            for (Point& p : points) {
                dist.push_back(abs(x - p.x) + abs(y - p.y));
            }

            sort(dist.begin(), dist.end());
            int dist_sum = 0;

            for (int i = 0; i < n; i++) {
                dist_sum += dist[i];
                dist_sum_min[i] = min(dist_sum_min[i], dist_sum);
            }
        }
    }

    for (int& v : dist_sum_min) {
        cout << v << ' ';
    }

    cout << '\n';
    return 0;
}
