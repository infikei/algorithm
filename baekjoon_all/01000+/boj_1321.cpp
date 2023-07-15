// Solve 2023-07-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[500001], seg[2000001];

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    int left_val = seg_init(node << 1, s, mid);
    int right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int qidx, int qval) {
    seg[node] += qval;
    if (s == e) return;

    int mid = (s + e) >> 1;
    if (qidx <= mid) seg_update(node << 1, s, mid, qidx, qval);
    else seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
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

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int qidx, qval;
            cin >> qidx >> qval;

            seg_update(1, 1, n, qidx, qval);
        }
        else {
            int qval;
            cin >> qval;

            int low = 0, high = n;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                int val = seg_query(1, 1, n, 1, mid);

                if (val >= qval) {
                    high = mid;
                }
                else {
                    low = mid;
                }
            }

            cout << high << '\n';
        }
    }

    return 0;
}
