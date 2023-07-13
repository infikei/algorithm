// Solve 2023-07-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int seg[4000001];

void seg_update(int node, int s, int e, int qidx, int qval) {
    seg[node] += qval;

    if (s == e) return;

    int mid = (s + e) >> 1;
    if (qidx <= mid) seg_update(node << 1, s, mid, qidx, qval);
    else seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
}

int seg_query(int node, int s, int e, int qval) {
    seg[node]--;

    if (s == e) return s;

    int mid = (s + e) >> 1;
    if (qval <= seg[node << 1]) return seg_query(node << 1, s, mid, qval);
    else return seg_query((node << 1) + 1, mid + 1, e, qval - seg[node << 1]);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b;
            cin >> b;
            cout << seg_query(1, 1, 1000000, b) << '\n';
        }
        else {
            int b, c;
            cin >> b >> c;
            seg_update(1, 1, 1000000, b, c);
        }
    }

    return 0;
}
