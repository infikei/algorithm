// Solve 2023-06-24

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
int seg[400001];

int dfs(int cur, int s) {
    int e = s;

    for (auto next : childs[cur]) {
        e = dfs(next, e + 1);
    }

    intervals[cur] = { s, e };
    return e;
}

void seg_update(int node, int s, int e, int qidx, int qval) {
    if (qidx < s || e < qidx) return;

    seg[node] += qval;
    if (s == e) return;

    int mid = (s + e) >> 1;
    if (qidx <= mid) {
        seg_update(node << 1, s, mid, qidx, qval);
    }
    else {
        seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
    }
}

int seg_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query(node << 1, s, mid, qs, qe);
    int right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        int pu;
        cin >> pu;
        if (pu == -1) continue;
        childs[pu].push_back(u);
    }

    dfs(1, 1);

    for (int i = 0; i < m; i++) {
        int cmd, u;
        cin >> cmd >> u;

        if (cmd == 1) {
            int qidx = intervals[u].s;
            int qval;
            cin >> qval;
            seg_update(1, 1, n, qidx, qval);
        }
        else {
            int qs = intervals[u].s;
            int qe = intervals[u].e;
            cout << seg_query(1, 1, n, qs, qe) << '\n';
        }
    }

    return 0;
}
