// Solve 2025-06-01

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

int get_digit_sum_with_base(int n, int base) {
    int res = 0;

    while (n > 0) {
        res += n % base;
        n /= base;
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int max_digit_sum = 0;
    int max_base = 0;

    for (int i = 2; i <= n; i++) {
        int digit_sum = get_digit_sum_with_base(n, i);

        if (digit_sum > max_digit_sum) {
            max_digit_sum = digit_sum;
            max_base = i;
        }
    }

    cout << max_digit_sum << ' ' << max_base << '\n';

    return 0;
}
