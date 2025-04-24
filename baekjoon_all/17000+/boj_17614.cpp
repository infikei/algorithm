// Solve 2022-11-06
// Update 2025-04-23

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

    int i = 1, i10 = 10, k = n;
    int cnt = 0;

    while (k > 0) {
        cnt += (n / i10) * 3 * i;
        cnt += min(max(0, n % i10 - 3 * i + 1), i);
        cnt += min(max(0, n % i10 - 6 * i + 1), i);
        cnt += min(max(0, n % i10 - 9 * i + 1), i);

        i *= 10;
        i10 *= 10;
        k /= 10;
    }

    cout << cnt << '\n';

    return 0;
}
