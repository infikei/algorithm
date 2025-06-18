// Solve 2024-06-19
// Update 2025-06-16

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
    int a, b;
    cin >> a >> b;

    cout << a / b << '.';
    a %= b;

    for (int i = 0; i < 1002; i++) {
        a *= 10;
        cout << a / b;
        a %= b;
    }

    cout << '\n';

    return 0;
}
