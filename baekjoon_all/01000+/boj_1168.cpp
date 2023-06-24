// Solve 2023-06-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int seg[400001];

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = 1;

    int mid = (s + e) >> 1;
    int left_val = seg_init(node << 1, s, mid);
    int right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

int seg_query(int node, int s, int e, int qval) {
    seg[node]--;
    if (s == e) return s;

    int mid = (s + e) >> 1;
    if (qval <= seg[node * 2]) {
        return seg_query(node << 1, s, mid, qval);
    }
    else {
        return seg_query((node << 1) + 1, mid + 1, e, qval - seg[node << 1]);
    }
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    seg_init(1, 1, n);

    cout << '<';

    for (int i = n, j = 0; i > 0; i--) {
        j += k;
        while (j > i) j -= i;

        if (i > 1) {
            cout << seg_query(1, 1, n, j) << ", ";
        }
        else {
            cout << seg_query(1, 1, n, j) << ">\n";
        }

        j--;
    }

    return 0;
}
