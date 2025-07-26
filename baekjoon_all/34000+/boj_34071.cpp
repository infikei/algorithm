// Solve 2025-07-24

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

    int n, x0;
    cin >> n >> x0;

    int min_x = x0;
    int max_x = x0;

    for (int i = 1; i < n; i++) {
        int xi;
        cin >> xi;
        min_x = min(min_x, xi);
        max_x = max(max_x, xi);
    }

    cout << (x0 == min_x ? "ez" : (x0 == max_x ? "hard" : "?")) << '\n';
    return 0;
}
