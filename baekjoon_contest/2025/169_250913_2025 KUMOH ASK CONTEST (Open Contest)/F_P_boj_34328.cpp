// Solve 2025-09-13

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

bool validate(int n) {
    if (n == 1) return true;
    if (n % 2 == 1) return false;
    return __builtin_popcount(n + 2) == 1;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (validate(n)) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }

        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
