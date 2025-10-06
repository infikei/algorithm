// Solve 2025-10-05

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

int cont[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;
    int m = 0;

    for (int i = 0; i < n; i++) {
        cin >> cont[i];
        m += cont[i];
    }

    int q = m / n;
    int r = m % n;
    sort(cont, cont + n);
    int ans = 0;

    for (int i = 0; i < n - r; i++) {
        ans += (cont[i] >= q) ? (cont[i] - q) : 0;
    }

    for (int i = n - r; i < n; i++) {
        ans += (cont[i] >= q + 1) ? (cont[i] - (q + 1)) : 0;
    }

    cout << ans << '\n';
    return 0;
}
