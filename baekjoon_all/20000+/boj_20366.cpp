// Solve 2025-10-08

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

ll snow[600];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }

    sort(snow, snow + n);
    ll min_diff = LLINF;

    for (int i = 0; i < n; i++) {
        for (int j = i + 3; j < n; j++) {
            ll snowman = snow[i] + snow[j];
            int l = i + 1;
            int r = j - 1;

            while (l < r) {
                ll snowman2 = snow[l] + snow[r];
                min_diff = min(min_diff, abs(snowman - snowman2));

                if (snowman2 > snowman) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
    }

    cout << min_diff << '\n';
    return 0;
}
