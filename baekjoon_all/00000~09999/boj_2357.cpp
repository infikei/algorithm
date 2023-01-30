#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int N, M;
int arr[100001], seg_min[400001], seg_max[400001];

void seg_init(int node, int s, int e) {
    if (s == e) {
        seg_min[node] = seg_max[node] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    seg_init(node * 2, s, mid);
    seg_init(node * 2 + 1, mid + 1, e);
    seg_min[node] = min(seg_min[node * 2], seg_min[node * 2 + 1]);
    seg_max[node] = max(seg_max[node * 2], seg_max[node * 2 + 1]);
}

pii seg_query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) {
        return make_pair(1000000001, 0);
    }
    if (l <= s && e <= r) {
        return make_pair(seg_min[node], seg_max[node]);
    }

    int mid = (s + e) / 2;
    pii left_val = seg_query(node * 2, s, mid, l, r);
    pii right_val = seg_query(node * 2 + 1, mid + 1, e, l, r);
    return make_pair(min(left_val.first, right_val.first), max(left_val.second, right_val.second));
}

int main() {
    fastio;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, N);

    int a, b;
    pii ans;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ans = seg_query(1, 1, N, a, b);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}