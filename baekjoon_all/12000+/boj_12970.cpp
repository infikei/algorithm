// Solve 2025-11-25

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

    int n, k;
    cin >> n >> k;

    int b = n / 2;
    int a = n - b;

    if (k > a * b) {
        cout << -1 << '\n';
        return 0;
    }

    int q = k / b;
    int r = k % b;

    int a1 = q;
    int b1 = b - r;
    int a2 = (r == 0 ? 0 : 1);
    int b2 = r;
    int a3 = a - a1 - a2;

    while (a1-- > 0) cout << 'A';
    while (b1-- > 0) cout << 'B';
    while (a2-- > 0) cout << 'A';
    while (b2-- > 0) cout << 'B';
    while (a3-- > 0) cout << 'A';
    cout << '\n';
    return 0;
}
