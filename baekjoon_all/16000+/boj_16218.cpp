// Solve 2025-10-15

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

int solution() {
    int n, k;
    cin >> n >> k;
    int a = 0;
    int b = 0;

    while (n-- > 0) {
        int x, y;
        cin >> x >> y;

        int a_op = a + x * 3 / 2;
        a += x;
        b += y;

        if (a_op >= k && b < k) {
            return 1;
        }
        else if (a_op < k && b >= k) {
            return -1;
        }
        else if (a_op >= k && b >= k) {
            return a >= k ? 1 : -1;
        }
        else if (a_op - b >= 50) {
            return 1;
        }
    }

    return 0;
}

int main() {
    FASTIO;

    cout << solution() << '\n';
    return 0;
}
