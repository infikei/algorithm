// Solve 2023-03-08
// Update 2025-07-27

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

    int n;
    cin >> n;
    int ans = 0;

    for (int a = 1; a <= 500; a++) {
        int a2 = a * a;

        for (int b = 1; b <= a; b++) {
            int b2 = b * b;

            if (a2 == b2 + n) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
