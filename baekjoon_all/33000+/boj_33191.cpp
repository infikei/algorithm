// Solve 2026-02-24

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

    int b, w, p, n;
    cin >> b >> w >> p >> n;

    if (w <= b) {
        cout << "Watermelon" << '\n';
    }
    else if (p <= b) {
        cout << "Pomegranates" << '\n';
    }
    else if (n <= b) {
        cout << "Nuts" << '\n';
    }
    else {
        cout << "Nothing" << '\n';
    }

    return 0;
}
