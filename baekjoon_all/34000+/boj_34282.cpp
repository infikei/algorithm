// Solve 2025-11-07

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

    int x, y, z;
    cin >> x >> y >> z;

    int score4 = x + y + z * 2;

    if (score4 >= 360) cout << 'A' << '\n';
    else if (score4 >= 320) cout << 'B' << '\n';
    else if (score4 >= 280) cout << 'C' << '\n';
    else if (score4 >= 240) cout << 'D' << '\n';
    else cout << 'F' << '\n';

    return 0;
}
