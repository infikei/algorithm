// Solve 2025-09-12

// 유사 문제 : 5025, 9497, 13435

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

int get_gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int f(int n, int m) {
    int gcd = get_gcd(n - 1, m - 1);

    if (gcd == 1) {
        return n * m / 2;
    }

    int nn = n / gcd + 1;
    int mm = m / gcd + 1;
    return f(nn, mm) + (n - nn) * (m / gcd);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int h, w;
        cin >> h >> w;
        cout << f(h, w) << '\n';
    }

    return 0;
}
