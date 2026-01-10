// Solve 2026-01-03

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

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        int sqrt_n = sqrt(n);

        int s = 0;

        for (int i = 1; i <= sqrt_n; i++) {
            if (n % i != 0) continue;

            int j = n / i;
            s += i;
            if (i != j) s += j;
        }

        s -= n;

        if (s < n) cout << "Deficient" << '\n';
        else if (s > n) cout << "Abundant" << '\n';
        else cout << "Perfect" << '\n';
    }

    return 0;
}
