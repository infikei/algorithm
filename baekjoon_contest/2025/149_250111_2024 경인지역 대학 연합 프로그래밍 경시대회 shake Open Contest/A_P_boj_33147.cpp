// Solve 2025-01-11
// Update 2025-02-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int get_gcd(int a, int b) {
    int r = a % b;

    return r == 0 ? b : get_gcd(b, r);
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    if (k != n) {
        k = get_gcd(k, n - k);
    }

    bool ans = true;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (abs(x - i) % k != 0) {
            ans = false;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
