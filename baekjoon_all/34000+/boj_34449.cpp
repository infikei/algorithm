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
const double PI = 3.14159;

int main() {
    FASTIO;

    double d, w;
    int n;
    cin >> d >> w >> n;

    if (d * PI >= w * n) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}
