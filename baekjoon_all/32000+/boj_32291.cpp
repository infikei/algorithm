// Solve 2025-10-24

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

    ll x;
    cin >> x;
    x++;
    int sqrt_x = sqrt(x);
    stack<ll> stck;

    for (int i = 1; i <= sqrt_x; i++) {
        if (x % i == 0) {
            cout << i << ' ';
            ll j = x / i;

            if (i < j && j < x) {
                stck.push(j);
            }
        }
    }

    while (!stck.empty()) {
        cout << stck.top() << ' ';
        stck.pop();
    }

    cout << '\n';
    return 0;
}
