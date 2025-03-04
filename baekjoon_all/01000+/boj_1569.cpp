// Solve 2024-02-02
// Update 2025-03-04

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x[50], y[50];
    int min_x = 1001, max_x = -1001;
    int min_y = 1001, max_y = -1001;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        min_x = min(min_x, x[i]);
        max_x = max(max_x, x[i]);
        min_y = min(min_y, y[i]);
        max_y = max(max_y, y[i]);
    }

    int len_x = max_x - min_x;
    int len_y = max_y - min_y;
    int square_len = max(len_x, len_y);

    if (len_x > len_y) {
        int y1 = max_y - square_len;
        int y2 = max_y;
        bool possible = false;

        while (y1 <= min_y) {
            bool all_points_on_square = true;

            for (int i = 0; i < n; i++) {
                if (x[i] != min_x && x[i] != max_x && y[i] != y1 && y[i] != y2) {
                    all_points_on_square = false;
                    break;
                }
            }

            if (all_points_on_square) {
                possible = true;
                break;
            }

            y1++;
            y2++;
        }

        if (!possible) {
            square_len = -1;
        }
    }
    else if (len_x < len_y) {
        int x1 = max_x - square_len;
        int x2 = max_x;
        bool possible = false;

        while (x1 <= min_x) {
            bool all_points_on_square = true;

            for (int i = 0; i < n; i++) {
                if (x[i] != x1 && x[i] != x2 && y[i] != min_y && y[i] != max_y) {
                    all_points_on_square = false;
                    break;
                }
            }

            if (all_points_on_square) {
                possible = true;
                break;
            }

            x1++;
            x2++;
        }

        if (!possible) {
            square_len = -1;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (x[i] != min_x && x[i] != max_x && y[i] != min_y && y[i] != max_y) {
                square_len = -1;
                break;
            }
        }
    }

    cout << square_len << '\n';

    return 0;
}
