// Solve 2023-02-16
// Update 2025-03-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int parents[500000];

int get_parent_of(int u) {
    if (parents[u] < 0) return u;

    return parents[u] = get_parent_of(parents[u]);
}

bool union_parents(int u1, int u2) {
    u1 = get_parent_of(u1);
    u2 = get_parent_of(u2);

    if (u1 == u2) return false;

    if (parents[u1] < parents[u2]) {
        parents[u1] += parents[u2];
        parents[u2] = u1;
    }
    else {
        parents[u2] += parents[u1];
        parents[u1] = u2;
    }

    return true;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 0; u < n; u++) {
        parents[u] = -1;
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        int u1, u2;
        cin >> u1 >> u2;

        if (!union_parents(u1, u2)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
