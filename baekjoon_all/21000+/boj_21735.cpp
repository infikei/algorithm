// Solve 2025-11-19

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

int n, m;
int a[110];
int mx = 0;

void recur(int depth, int cur_pos, int cur_size) {
    if (depth == m || cur_pos > n) {
        mx = max(mx, cur_size);
        return;
    }

    recur(depth + 1, cur_pos + 1, cur_size + a[cur_pos + 1]);
    recur(depth + 1, cur_pos + 2, cur_size / 2 + a[cur_pos + 2]);
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    recur(0, 0, 1);
    cout << mx << '\n';
    return 0;
}
