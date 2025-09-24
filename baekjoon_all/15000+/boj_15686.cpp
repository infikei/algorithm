// Solve 2022-09-12
// Update 2025-09-23

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

    int get_dist(Point& rhs) {
        return abs(x - rhs.x) + abs(y - rhs.y);
    }
};

int n, m;
int min_sum_dist;
vector<Point> houses;
vector<Point> chickens;
vector<int> selected_chickens;

void recur(int depth = 0, int begin_idx = 0) {
    if (depth == m) {
        int city_chicken_dist = 0;

        for (Point& house : houses) {
            int chicken_dist = 100;

            for (int c_idx : selected_chickens) {
                chicken_dist = min(chicken_dist, house.get_dist(chickens[c_idx]));
            }

            city_chicken_dist += chicken_dist;
        }

        min_sum_dist = min(min_sum_dist, city_chicken_dist);
        return;
    }

    for (int i = begin_idx; i < size(chickens); i++) {
        selected_chickens.push_back(i);
        recur(depth + 1, i + 1);
        selected_chickens.pop_back();
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int val;
            cin >> val;

            if (val == 1) {
                houses.emplace_back(x, y);
            }
            else if (val == 2) {
                chickens.emplace_back(x, y);
            }
        }
    }

    min_sum_dist = INF;
    recur();
    cout << min_sum_dist << '\n';
    return 0;
}
