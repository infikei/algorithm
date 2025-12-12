// Solve 2025-12-08
// Update 2025-12-10

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

struct IPhone{
    int x, y, v, p;

    IPhone(int x, int y, int v, int p) : x(x), y(y), v(v), p(p) {
    }
};

int parent[3001];
vector<IPhone> phones;

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u, int v) {
    u = get_parent_of(u);
    v = get_parent_of(v);

    if (u == v) return;

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}

int get_dist_square(int u, int v) {
    int dx = phones[u].x - phones[v].x;
    int dy = phones[u].y - phones[v].y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int n, k, t;
    cin >> n >> k >> t;
    int k2 = k * k;

    {
        int x, y, v;
        cin >> x >> y >> v;
        phones.emplace_back(x, y, v, 0);
    }

    for (int u = 1; u <= n; u++) {
        int x, y, v, p;
        cin >> x >> y >> v >> p;
        phones.emplace_back(x, y, v, p);
    }

    memset(parent, -1, sizeof parent);

    for (int u = 0; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (get_dist_square(u, v) <= k2 && abs(phones[u].v - phones[v].v) <= t) {
                union_parents(u, v);
            }
        }
    }

    int cnt = 0;

    for (int u = 1; u <= n; u++) {
        if (phones[u].p == 1 && get_parent_of(u) == get_parent_of(0)) {
            cout << u << ' ';
            cnt++;
        }
    }

    if (cnt == 0) {
        cout << 0;
    }

    cout << '\n';
    return 0;
}
