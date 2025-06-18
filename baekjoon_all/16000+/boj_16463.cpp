// Solve 2025-06-14
// Update 2025-06-16

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

int month_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap_year(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int friday_13th_cnt = 0;
    int day_of_13th = 0;

    for (int y = 2019; y <= n; y++) {
        month_days[2] = is_leap_year(y) ? 29 : 28;

        for (int m = 1; m <= 12; m++) {
            if (day_of_13th == 5) friday_13th_cnt++;

            day_of_13th = (day_of_13th + month_days[m]) % 7;
        }
    }

    cout << friday_13th_cnt << '\n';

    return 0;
}
