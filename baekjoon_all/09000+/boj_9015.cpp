// Solve 2025-03-12

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
    int x, y;
};

Point points[3000];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        unordered_set<int> hs;

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;

            points[i].x += 10000;
            points[i].y += 10000;
            hs.insert((points[i].x << 15) + points[i].y);
        }

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;

                int nx1 = points[i].x + dy;
                int ny1 = points[i].y - dx;
                int nx2 = points[j].x + dy;
                int ny2 = points[j].y - dx;

                if (hs.find((nx1 << 15) + ny1) != hs.end() && hs.find((nx2 << 15) + ny2) != hs.end()) {
                    max_area = max(max_area, dx * dx + dy * dy);
                }
            }
        }

        cout << max_area << '\n';
    }

    return 0;
}
