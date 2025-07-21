// Solve 2025-07-20

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

int n;
int beads[6];
ll memo[6][6][11][11][11][11][11];

ll recur(int pprev, int prev) {
    if (beads[1] == 0 && beads[2] == 0 && beads[3] == 0 && beads[4] == 0 && beads[5] == 0) {
        return 1;
    }

    ll& ret = memo[pprev][prev][beads[1]][beads[2]][beads[3]][beads[4]][beads[5]];

    if (ret != -1) {
        return ret;
    }

    ret = 0;

    for (int i = 1; i <= n; i++) {
        if (i == pprev || i == prev || beads[i] <= 0) continue;

        beads[i]--;
        ret += recur(prev, i);
        beads[i]++;
    }

    return ret;
}

int main() {
    FASTIO;

    memset(memo, -1, sizeof memo);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> beads[i];
    }

    cout << recur(0, 0) << '\n';
    return 0;
}
