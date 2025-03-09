// Solve 2025-03-08

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

int x[4];
int y[4];

double get_dist(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];

    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    double min_dist_sum = 1000;

    for (int a = 1; a < 4; a++) {
        double dist = get_dist(0, a);

        for (int b = 1; b < 4; b++) {
            if (b == a) continue;

            double dist2 = dist + get_dist(a, b);

            for (int c = 1; c < 4; c++) {
                if (c == a || c == b) continue;

                double dist_sum = dist2 + get_dist(b, c);
                min_dist_sum = min(min_dist_sum, dist_sum);
            }
        }
    }

    cout << (int) min_dist_sum << '\n';

    return 0;
}
