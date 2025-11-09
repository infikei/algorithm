// Solve 2025-11-09

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

set<int> adj[100001];
int input_dfs[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> input_dfs[i];
    }

    if (input_dfs[0] != 1) {
        cout << 0 << '\n';
        return 0;
    }

    stack<int> stck;
    stck.push(1);

    for (int i = 1; i < n; i++) {
        int u = input_dfs[i];

        while (!stck.empty() && adj[stck.top()].find(u) == adj[stck.top()].end()) {
            stck.pop();
        }

        if (stck.empty()) {
            cout << 0 << '\n';
            return 0;
        }

        stck.push(u);
    }

    cout << 1 << '\n';
    return 0;
}
