// Solve 2022-07-24
// Update 2025-02-21

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

int lengths[10000];

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> lengths[i];
    }

    ll low = 1;
    ll high = 2147483648LL;

    while (low + 1 < high) {
        ll mid = (low + high) >> 1;
        ll mid_val = 0;

        for (int i = 0; i < k; i++) {
            mid_val += lengths[i] / mid;
        }

        if (mid_val >= n) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}
