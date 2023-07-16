// Solve 2023-07-16

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

int salary0[500001];
int salary[500001], lazy[2000001];
Interval interval[500001];
vector<int> child[500001];

int dfs(int u, int s) {
    int e = s;
    salary[s] = salary0[u];

    for (auto nu : child[u]) {
        e = dfs(nu, e + 1);
    }

    interval[u] = { s, e };
    return e;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        if (s == e) {
            salary[s] += lazy[node];
        }
        else {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
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
        lazy[node] += qval;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update(node << 1, s, mid, qs, qe, qval);
    seg_update((node << 1) + 1, mid + 1, e, qs, qe, qval);
}

int seg_query(int node, int s, int e, int qidx) {
    seg_lazy_update(node, s, e);

    if (s == e) return salary[s];

    int mid = (s + e) >> 1;
    if (qidx <= mid) return seg_query(node << 1, s, mid, qidx);
    else return seg_query((node << 1) + 1, mid + 1, e, qidx);
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    cin >> salary0[1];
    for (int u = 2; u <= n; u++) {
        int pu;
        cin >> salary0[u] >> pu;
        child[pu].push_back(u);
    }

    dfs(1, 1);

    for (int i = 0; i < m; i++) {
        char cmd;
        int u;
        cin >> cmd >> u;

        if (cmd == 'p') {
            int qval;
            cin >> qval;

            int qs = interval[u].s + 1;
            int qe = interval[u].e;
            if (qs <= qe) seg_update(1, 1, n, qs, qe, qval);
        }
        else {
            cout << seg_query(1, 1, n, interval[u].s) << '\n';
        }
    }

    return 0;
}
