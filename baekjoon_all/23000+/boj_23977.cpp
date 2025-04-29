// Solve 2025-04-29

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

ll get_gcd(ll a, ll b) {
    while (b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll get_lcm(ll a, ll b) {
    return a / get_gcd(a, b) * b;
}

ll find_password(int k, vector<int> &a) {
    ll ans = 1;

    for (int &ai : a) {
        ans = get_lcm(ans, ai);
    }

    return ans - k;
}

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    cout << find_password(k, a) << '\n';

    return 0;
}
