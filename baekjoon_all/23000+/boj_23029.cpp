// Solve 2025-11-18

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

    int n, v;
    cin >> n >> v;

    int memo[3] = {0, v, 0};
    int tmp[3];

    for (int i = 1; i < n; i++) {
        cin >> v;

        tmp[0] = max(memo[0], max(memo[1], memo[2]));
        tmp[1] = memo[0] + v;
        tmp[2] = memo[1] + v / 2;

        swap(memo, tmp);
    }

    cout << max(memo[0], max(memo[1], memo[2])) << '\n';
    return 0;
}
