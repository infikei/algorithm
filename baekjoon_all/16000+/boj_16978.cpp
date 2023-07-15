// Solve 2023-07-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Query{
    int t, q1, q2, a, b;
    Query(int nt = 0, int nq1 = 0, int nq2 = 0, int na = 0, int nb = 0) : t(nt), q1(nq1), q2(nq2), a(na), b(nb) {}
    bool operator<(const Query &rhs) const {
        if (q1 != rhs.q1) return q1 < rhs.q1;
        if (t != rhs.t) return t < rhs.t;
        if (a != rhs.a) return a < rhs.a;
        if (b != rhs.b) return b < rhs.b;
        return q2 < rhs.q2;
    }
};

ll arr[100001], seg[400001];
Query query[100000];

ll seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_init(node << 1, s, mid);
    ll right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int qidx, int qval) {
    if (qidx < s || e < qidx) return;
    if (s == e) {
        seg[node] = qval;
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node << 1, s, mid, qidx, qval);
    seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
    seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

ll seg_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node << 1, s, mid, qs, qe);
    ll right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    // 수열 입력

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리 초기화

    seg_init(1, 1, n);

    // 쿼리 입력

    int m;
    cin >> m;

    int query1 = 0, query2 = 0;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            cin >> a >> b;
            query[i] = { t, ++query1, 0, a, b };
        }
        else {
            int k, a, b;
            cin >> k >> a >> b;
            query[i] = { t, k, ++query2, a, b };
        }
    }

    // 쿼리 정렬

    sort(query, query + m);

    // 쿼리 처리

    for (int i = 0; i < m; i++) {
        if (query[i].t == 1) {
            seg_update(1, 1, n, query[i].a, query[i].b);
        }
        else {
            arr[query[i].q2] = seg_query(1, 1, n, query[i].a, query[i].b);
        }
    }

    // 답 출력

    for (int i = 1; i <= query2; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
