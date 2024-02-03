// Solve 2024-02-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

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
    int len_square = max(len_x, len_y);

    if (len_x > len_y) {
        int y1 = max_y - len_square;
        int y2 = max_y;
        bool flag_possible = false;

        while (y1 <= min_y) {
            bool flag = true;

            for (int i = 0; i < n; i++) {
                if (x[i] != min_x && x[i] != max_x && y[i] != y1 && y[i] != y2) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                flag_possible = true;
                break;
            }

            y1++;
            y2++;
        }

        if (!flag_possible) len_square = -1;
    }
    else if (len_x < len_y) {
        int x1 = max_x - len_square;
        int x2 = max_x;
        bool flag_possible = false;

        while (x1 <= min_x) {
            bool flag = true;

            for (int i = 0; i < n; i++) {
                if (x[i] != x1 && x[i] != x2 && y[i] != min_y && y[i] != max_y) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                flag_possible = true;
                break;
            }

            x1++;
            x2++;
        }

        if (!flag_possible) len_square = -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (x[i] != min_x && x[i] != max_x && y[i] != min_y && y[i] != max_y) {
                len_square = -1;
                break;
            }
        }
    }

    cout << len_square << '\n';

    return 0;
}
