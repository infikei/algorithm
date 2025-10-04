// Solve 2025-10-04

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

int n, m, k;
int card[4000001];
int parent[4000001];

int get_parent_of(int u) {
    if (parent[u] == u) return u;

    return parent[u] = get_parent_of(parent[u]);
}

int main() {
    FASTIO;

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> card[i];
        parent[i] = i;
    }

    parent[m] = m;
    sort(card, card + m);

    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;

        int idx = upper_bound(card, card + m, v) - card;
        int par = get_parent_of(idx);
        cout << card[par] << '\n';
        parent[par] = par + 1;
    }

    return 0;
}
