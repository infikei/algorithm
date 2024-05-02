// Solve 2024-05-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Circle{
    int x, y, r;
};

int n;
Circle circles[3000];
int parent[3000];

int get_parent_of(int u) {
    if (parent[u] < 0) return u;

    return parent[u] = get_parent_of(parent[u]);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        int ans = n;

        for (int i = 0; i < n; i++) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
            parent[i] = -1;
        }

        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int dx = circles[u].x - circles[v].x;
                int dy = circles[u].y - circles[v].y;
                int r_sum = circles[u].r + circles[v].r;

                if (r_sum * r_sum >= dx * dx + dy * dy) {
                    int pu = get_parent_of(u);
                    int pv = get_parent_of(v);

                    if (pu != pv) {
                        if (parent[pu] < parent[pv]) {
                            parent[pu] += parent[pv];
                            parent[pv] = pu;
                        }
                        else {
                            parent[pv] += parent[pu];
                            parent[pu] = pv;
                        }

                        ans--;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
