// Solve 2025-11-30

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

vector<int> adj[200001];
bool visited[200001];
int cnt[200001];

int main() {
    FASTIO;

    int n, m, q;
    cin >> n >> m >> q;

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q-- > 0) {
        int cmd, u;
        cin >> cmd >> u;

        if (cmd == 1) {
            if (!visited[u]) {
                visited[u] = true;

                for (int nu : adj[u]) {
                    cnt[nu]++;
                }
            }
        }
        else {
            cout << cnt[u] << '\n';
        }
    }

    return 0;
}
