// Solve 2025-08-10

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

vector<int> subordinates[100001];
int praise_sum[100001];

void dfs(int u) {
    for (int nu : subordinates[u]) {
        praise_sum[nu] += praise_sum[u];
        dfs(nu);
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        int pu;
        cin >> pu;
        if (pu == -1) continue;
        subordinates[pu].push_back(u);
    }

    while (m-- > 0) {
        int u, w;
        cin >> u >> w;
        praise_sum[u] += w;
    }

    dfs(1);

    for (int u = 1; u <= n; u++) {
        cout << praise_sum[u] << ' ';
    }

    cout << '\n';
    return 0;
}
