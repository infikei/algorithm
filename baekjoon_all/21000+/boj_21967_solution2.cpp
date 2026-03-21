// Solve 2026-03-09

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

int a[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx_len = 1;

    for (int i = 1, j = 3; j <= 10; i++, j++) {
        int cur_len = 0;

        for (int u = 0; u < n; u++) {
            if (i <= a[u] && a[u] <= j) {
                cur_len++;
            }
            else {
                mx_len = max(mx_len, cur_len);
                cur_len = 0;
            }
        }

        mx_len = max(mx_len, cur_len);
    }

    cout << mx_len << '\n';
    return 0;
}
