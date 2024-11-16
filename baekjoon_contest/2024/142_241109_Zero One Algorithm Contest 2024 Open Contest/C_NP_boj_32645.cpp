// Solve 2024-11-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

vector<int> adj[100001];
char ans[100001];

void dfs(int cur, int par) {
    char res = 'u';

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        dfs(nxt, cur);

        if (ans[nxt] == 'u') {
            res = 'd';
        }
    }

    ans[cur] = res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int u = 1; u <= n; u++) {
        println(ans[u] == 'd' ? "donggggas" : "uppercut");
    }

    return 0;
}
