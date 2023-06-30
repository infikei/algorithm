// Solve 2023-06-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Interval{
    int s, e;
    Interval(int ns = 0, int ne = 0) : s(ns), e(ne) {}
};

Interval intervals[100001];
vector<int> childs[100001];
int seg[400001], lazy[400001];

int dfs(int cur, int s) {
    int e = s;

    for (auto next : childs[cur]) {
        e = dfs(next, e + 1);
    }

    intervals[cur] = { s, e };
    return e;
}

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = 1;

    int mid = (s + e) >> 1;
    int left_val = seg_init(node << 1, s, mid);
    int right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        seg[node] = (lazy[node] - 1) * (e - s + 1);

        if (s != e) {
            lazy[node << 1] = lazy[node];
            lazy[(node << 1) + 1] = lazy[node];
        }

        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe, int qval) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] = qval + 1;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node << 1, s, mid, qs, qe, qval);
    seg_update((node << 1) + 1, mid + 1, e, qs, qe, qval);
    seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

int seg_query(int node, int s, int e, int qs, int qe) {
    seg_lazy_update(node, s, e);

    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query(node << 1, s, mid, qs, qe);
    int right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        int pu;
        cin >> pu;
        if (pu == 0) continue;
        childs[pu].push_back(u);
    }

    dfs(1, 1);

    seg_init(1, 1, n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd, u;
        cin >> cmd >> u;

        int qs = intervals[u].s + 1;
        int qe = intervals[u].e;

        if (cmd == 1) {
            seg_update(1, 1, n, qs, qe, 1);
        }
        else if (cmd == 2) {
            seg_update(1, 1, n, qs, qe, 0);
        }
        else {
            cout << seg_query(1, 1, n, qs, qe) << '\n';
        }
    }

    return 0;
}
