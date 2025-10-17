// Solve 2025-10-17

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

int parent[300001];
int val[300001];
int idx[300001];

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

int main() {
    FASTIO;

    memset(parent, -1, sizeof parent);
    memset(val, -1, sizeof val);
    memset(idx, -1, sizeof idx);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;

        if (idx[v] == -1) {
            idx[v] = i;
            val[i] = v;
        }
        else {
            int p = idx[v];
            parent[i] = p;
            parent[p]--;
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int v1, v2;
            cin >> v1 >> v2;

            if (v1 == v2) continue;

            int p1 = idx[v1];
            int p2 = idx[v2];

            if (p1 == -1) {
                continue;
            }
            else if (p2 == -1) {
                idx[v1] = -1;
                idx[v2] = p1;
                val[p1] = v2;
            }
            else if (parent[p1] <= parent[p2]) {
                parent[p1] += parent[p2];
                parent[p2] = p1;
                idx[v1] = -1;
                idx[v2] = p1;
                val[p1] = v2;
                val[p2] = -1;
            }
            else {
                parent[p2] += parent[p1];
                parent[p1] = p2;
                idx[v1] = -1;
                val[p1] = -1;
            }
        }
        else {
            int u;
            cin >> u;
            cout << val[get_parent_of(u)] << '\n';
        }
    }

    return 0;
}
