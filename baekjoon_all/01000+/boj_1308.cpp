// Solve 2025-01-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int convert_date_to_int(int y, int m, int d) {
    int res = 365 * y + ((y - 1) / 4) - ((y - 1) / 100) + ((y - 1) / 400);

    int month_days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    res += month_days[m - 1] + d;

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        if (m >= 3) {
            res++;
        }
    }

    return res;
}

int main() {
    FASTIO;

    int y0, m0, d0;
    cin >> y0 >> m0 >> d0;

    int today = convert_date_to_int(y0, m0, d0);

    int y1, m1, d1;
    cin >> y1 >> m1 >> d1;

    int nxt = convert_date_to_int(y1, m1, d1);

    if (y1 > y0 + 1000 || (y1 == y0 + 1000 && m1 * 100 + d1 >= m0 * 100 + d0)) {
        println("gg");
    }
    else {
        cout << "D-" << nxt - today << '\n';
    }

    return 0;
}
