// Solve 2025-08-29

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

bool solution(ll n) {
    ll fac = 1;
    ll fac_sum = 1;

    for (ll i = 1; i <= 20; i++) {
        fac *= i;
        fac_sum += fac;
        
        if (n < fac) {
            return false;
        }
        else if (n <= fac_sum) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    cout << (solution(n) ? "YES" : "NO") << '\n';
    return 0;
}
