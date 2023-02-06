#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, M, arr[100001], seg[400001];

int seg_init(int node, int s, int e) {
    if (s == e) {
        return seg[node] = arr[s];
    }

    int mid = (s + e) / 2;
    int left_val = seg_init(node * 2, s, mid);
    int right_val = seg_init(node * 2 + 1, mid + 1, e);
    return seg[node] = min(left_val, right_val);
}

int seg_query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) {
        return 1000000001;
    }
    if (l <= s && e <= r) {
        return seg[node];
    }

    int mid = (s + e) / 2;
    int left_val = seg_query(node * 2, s, mid, l, r);
    int right_val = seg_query(node * 2 + 1, mid + 1, e, l, r);
    return min(left_val, right_val);
}

int main() {
    fastio;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, N);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << seg_query(1, 1, N, a, b) << '\n';
    }

    return 0;
}