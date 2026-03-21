// Solve 2026-03-04

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
using pi4 = pair<pii, pii>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int par[100001][3];
int grsz[100001][3];

int get_parent_of(int u, int i) {
    if (par[u][i] == u) return u;

    return par[u][i] = get_parent_of(par[u][i], i);
}

void union_parents(int u, int v, int i) {
    u = get_parent_of(u, i);
    v = get_parent_of(v, i);

    if (grsz[u] > grsz[v]) {
        swap(u, v);
    }

    grsz[u][i] += grsz[v][i];
    par[v][i] = u;
}

int main() {
    FASTIO;

    memset(grsz, -1, sizeof(grsz));

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < 3; i++) {
            par[u][i] = u;
        }
    }

    int m[3];

    for (int i = 0; i < 3; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < m[i]; j++) {
            int u, v;
            cin >> u >> v;

            union_parents(u, v, i);
        }
    }

    vector<pi4> vec;

    for (int u = 1; u <= n; u++) {
        vec.push_back({{get_parent_of(u, 0), get_parent_of(u, 1)}, {get_parent_of(u, 2), u}});
    }

    sort(vec.begin(), vec.end());

    vector<vector<int>> ans;
    vector<int> cur;
    cur.push_back(vec[0].second.second);

    for (int i = 1; i < size(vec); i++) {
        if (vec[i - 1].first.first == vec[i].first.first && vec[i - 1].first.second == vec[i].first.second && vec[i - 1].second.first == vec[i].second.first) {
            cur.push_back(vec[i].second.second);
        }
        else {
            if (size(cur) >= 2) {
                sort(cur.begin(), cur.end());
                ans.push_back(cur);
            }

            cur.clear();
            cur.push_back(vec[i].second.second);
        }
    }

    if (size(cur) >= 2) {
        sort(cur.begin(), cur.end());
        ans.push_back(cur);
    }

    sort(ans.begin(), ans.end());
    cout << size(ans) << '\n';

    for (auto& v : ans) {
        for (int u : v) {
            cout << u << ' ';
        }

        cout << '\n';
    }

    return 0;
}
