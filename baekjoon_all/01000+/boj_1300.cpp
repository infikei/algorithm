// Solve 2022-12-07
// Update 2025-02-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    ll n, k;
    cin >> n >> k;

    ll low = 0, high = 10000000000LL;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;

        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        if (cnt < k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    println(high);

    return 0;
}
