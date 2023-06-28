// Solve 2023-06-27

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
int arr[100001], lazy[400001];
int seg2[400001];

int dfs(int cur, int s) {
    int e = s;

    for (auto next : childs[cur]) {
        e = dfs(next, e + 1);
    }

    intervals[cur] = { s, e };
    return e;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        if (s == e) {
            arr[s] += lazy[node];
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

    if (s == e) return arr[s];

    int mid = (s + e) >> 1;
    if (qidx <= mid) {
        return seg_query(node << 1, s, mid, qidx);
    }
    else {
        return seg_query((node << 1) + 1, mid + 1, e, qidx);
    }
}

void seg2_update(int node, int s, int e, int qidx, int qval) {
    seg2[node] += qval;

    if (s == e) return;

    int mid = (s + e) >> 1;
    if (qidx <= mid) {
        seg2_update(node << 1, s, mid, qidx, qval);
    }
    else {
        seg2_update((node << 1) + 1, mid + 1, e, qidx, qval);
    }
}

int seg2_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg2[node];

    int mid = (s + e) >> 1;
    int left_val = seg2_query(node << 1, s, mid, qs, qe);
    int right_val = seg2_query((node << 1) + 1, mid + 1, e, qs, qe);
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

    int direction = 0;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int u, qval;
            cin >> u >> qval;

            int qs = intervals[u].s;
            int qe = intervals[u].e;

            if (direction == 0) {
                seg_update(1, 1, n, qs, qe, qval);
            }
            else {
                seg2_update(1, 1, n, qs, qval);
            }
        }
        else if (cmd == 2) {
            int u;
            cin >> u;

            int qs = intervals[u].s;
            int qe = intervals[u].e;
            cout << seg_query(1, 1, n, qs) + seg2_query(1, 1, n, qs, qe) << '\n';
        }
        else {
            direction ^= 1;
        }
    }

    return 0;
}
