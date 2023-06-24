// Solve 2023-06-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int seg[8000001];

void seg_update(int node, int s, int e, int qidx) {
    if (qidx < s || e < qidx) return;

    seg[node]++;
    if (s == e) return;

    int mid = (s + e) >> 1;
    seg_update(node << 1, s, mid, qidx);
    seg_update((node << 1) + 1, mid + 1, e, qidx);
}

int seg_query(int node, int s, int e, int qval) {
    seg[node]--;
    if (s == e) return s;

    int mid = (s + e) >> 1;
    if (qval <= seg[node << 1]) {
        return seg_query(node << 1, s, mid, qval);
    }
    else {
        return seg_query((node << 1) + 1, mid + 1, e, qval - seg[node << 1]);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cmd, x;
        cin >> cmd >> x;

        if (cmd == 1) {
            seg_update(1, 1, 2000000, x);
        }
        else {
            cout << seg_query(1, 1, 2000000, x) << '\n';
        }
    }

    return 0;
}
