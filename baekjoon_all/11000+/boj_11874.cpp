// Solve 2025-08-17

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

int main() {
    FASTIO;

    int l, d, x;
    cin >> l >> d >> x;

    int first = -1;
    int last = -1;

    for (int num = l; num <= d; num++) {
        int digit_sum = 0;
        int tmp = num;

        while (tmp > 0) {
            digit_sum += tmp % 10;
            tmp /= 10;
        }

        if (digit_sum == x) {
            if (first == -1) first = num;

            last = num;
        }
    }

    cout << first << '\n';
    cout << last << '\n';
    return 0;
}
