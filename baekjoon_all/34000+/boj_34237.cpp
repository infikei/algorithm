// Solve 2026-04-24

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

int a[50];
int b[50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    while (m-- > 0) {
        int g, x, y;
        cin >> g >> x >> y;

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (x <= a[i] && y <= b[i] && a[i] + b[i] <= g) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
