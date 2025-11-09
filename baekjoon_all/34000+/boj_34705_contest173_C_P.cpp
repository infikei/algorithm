// Solve 2025-11-08

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

int x, y;
int a[5];

bool recur(int depth, int w) {
    if (depth == 5) {
        return w >= x && w <= y;
    }

    if (recur(depth + 1, w + a[depth])) {
        return true;
    }

    if (recur(depth + 1, w)) {
        return true;
    }

    return false;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> x >> y;

        for (int i = 0; i < 5; i++) {
            cin >> a[i];
        }

        cout << (recur(0, 0) ? "YES" : "NO") << '\n';
    }

    return 0;
}
