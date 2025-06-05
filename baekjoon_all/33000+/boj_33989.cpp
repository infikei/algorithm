// Solve 2025-06-02

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

int prefix_sum[100001];

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1];

        if (s[i - 1] == 'B') {
            prefix_sum[i]++;
        }
    }

    int ans = n;

    for (int i = 0; i <= n; i++) {
        // int cur = (i - prefix_sum[i]) + (prefix_sum[n] - prefix_sum[i]);
        int cur = i + prefix_sum[n] - prefix_sum[i] * 2;
        ans = min(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
