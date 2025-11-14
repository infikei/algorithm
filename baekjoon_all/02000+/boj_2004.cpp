// Solve 2022-06-08
// Update 2025-11-12

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

ll count_prime_in_factorial(ll n, ll p) {
    ll cnt = 0;

    while (n > 0) {
        n /= p;
        cnt += n;
    }

    return cnt;
}

int main() {
    FASTIO;

    ll n, m;
    cin >> n >> m;

    ll cnt2 = count_prime_in_factorial(n, 2);
    cnt2 -= count_prime_in_factorial(m, 2);
    cnt2 -= count_prime_in_factorial(n - m, 2);

    ll cnt5 = count_prime_in_factorial(n, 5);
    cnt5 -= count_prime_in_factorial(m, 5);
    cnt5 -= count_prime_in_factorial(n - m, 5);

    cout << min(cnt2, cnt5) << '\n';

    return 0;
}
