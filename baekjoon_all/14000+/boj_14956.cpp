// Solve 2025-04-01

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

    int n, m;
    cin >> n >> m;

    int square[2][2] = {
        { 1, 2 },
        { 4, 3 }
    };

    int x = 0;
    int y = 0;

    while (n > 1) {
        int nn = n * n;
        int square_num = 1;

        while (m > nn / 4 * square_num) {
            square_num++;
        }

        m -= nn / 4 * (square_num - 1);
        int sx = 0;
        int sy = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (square[i][j] == square_num) {
                    sx = i;
                    sy = j;
                }
            }
        }

        if (square_num == 1 || square_num == 4) {
            swap(square[1 - sx][sy], square[sx][1 - sy]);
        }

        x = x * 2 + sx;
        y = y * 2 + sy;
        n /= 2;
    }

    cout << ++x << ' ' << ++y << '\n';

    return 0;
}
