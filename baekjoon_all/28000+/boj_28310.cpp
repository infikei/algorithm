// Solve 2026-04-18

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

struct Frac{
    ll child = 0;
    ll par = 1;

    Frac() {
        child = 0;
        par = 1;
    }

    Frac(ll child, ll par) : child(child), par(par) {
        reduce_frac();
    }

    ll get_gcd(ll a, ll b) {
        a = abs(a);
        b = abs(b);

        while (b != 0) {
            ll r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    void reduce_frac() {
        if (child == 0) {
            par = 1;
            return;
        }

        ll g = get_gcd(child, par);
        child /= g;
        par /= g;
    }

    Frac& operator+=(const Frac& other) {
        child = child * other.par + other.child * par;
        par = par * other.par;
        reduce_frac();
        return *this;
    }

    Frac operator+(const Frac& other) const {
        Frac res = *this;
        res += other;
        return res;
    }

    Frac& operator-=(const Frac& other) {
        child = child * other.par - other.child * par;
        par = par * other.par;
        reduce_frac();
        return *this;
    }

    Frac operator-(const Frac& other) const {
        Frac res = *this;
        res -= other;
        return res;
    }

    bool operator<(const Frac& other) const {
        return child * other.par < other.child * par;
    }
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        vector<Frac> cookies(n);

        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;

            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                cookies[i] += {a, v};
            }
        }

        sort(cookies.begin(), cookies.end());
        Frac diff = cookies[n - 1] - cookies[0];

        if (diff.par == 1) {
            cout << diff.child << '\n';
        }
        else {
            cout << diff.child << '/' << diff.par << '\n';
        }
    }

    return 0;
}
