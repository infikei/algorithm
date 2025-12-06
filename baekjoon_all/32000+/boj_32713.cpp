// Solve 2025-12-06

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

int a[5000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int v = a[i];
        int cur = 1;
        int rm = 0;

        for (int j = i + 1; j < n; j++) {
            if (a[j] == v) {
                cur++;
            }
            else {
                if (rm == k) break;

                rm++;
            }
        }

        mx = max(mx, cur);
    }

    cout << mx << '\n';
    return 0;
}
