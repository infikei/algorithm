// Solve 2026-02-19

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
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;

        for (int a = 1, b = i; a <= b; a++, b--) {
            if (get_gcd(a, b) == 1) {
                cnt++;
            }
        }

        int j = n / i;

        if (i == j) continue;

        for (int a = 1, b = j; a <= b; a++, b--) {
            if (get_gcd(a, b) == 1) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
