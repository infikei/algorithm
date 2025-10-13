// Solve 2025-10-13

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

ll x[200000];

int main() {
    FASTIO;

    int n;
    ll box_len;
    cin >> n >> box_len;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll suffix_sum = 0;

    for (int i = n - 2, j = 1; i >= 0; i--, j++) {
        suffix_sum += x[i + 1];

        if (j * (x[i] - box_len) >= suffix_sum || suffix_sum >= j * (x[i] + box_len)) {
            cout << "unstable" << '\n';
            return 0;
        }
    }

    cout << "stable" << '\n';
    return 0;
}
