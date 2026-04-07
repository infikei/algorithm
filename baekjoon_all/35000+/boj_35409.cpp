// Solve 2026-03-28

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

int timetable[8][2] = {
    {630, 900},
    {950, 1000},
    {1050, 1100},
    {1150, 1200},
    {1250, 1350},
    {1440, 1450},
    {1540, 1550},
    {1640, 2250}
};

int main() {
    FASTIO;

    int h, m;
    cin >> h >> m;

    int t = h * 100 + m;

    for (int i = 0; i < 8; i++) {
        if (t >= timetable[i][0] && t <= timetable[i][1]) {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
    return 0;
}
