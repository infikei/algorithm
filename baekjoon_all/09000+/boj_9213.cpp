// Solve 2026-01-02

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

int divisor_sum[1000000];

int main() {
    FASTIO;

    for (int i = 1; i < 1000000; i++) {
        for (int j = i * 2; j < 1000000; j += i) {
            divisor_sum[j] += i;
        }
    }

    int ti = 0;

    while (true) {
        int s, e, k;
        cin >> s >> e >> k;

        if (s == 0 && e == 0 && k == 0) break;

        int cnt = 0;

        for (int i = s; i <= e; i++) {
            if (abs(i - divisor_sum[i]) <= k) {
                cnt++;
            }
        }

        ti++;
        cout << "Test " << ti << ": " << cnt << '\n';
    }

    return 0;
}
