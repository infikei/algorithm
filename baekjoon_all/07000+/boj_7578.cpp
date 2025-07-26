// Solve 2025-07-17
// Update 2025-07-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int arr[500000];
int len = 1 << 19;
int tree[1 << 20];

void update_seg(int idx, int val) {
    idx += len;
    tree[idx] = val;
    idx /= 2;

    while (idx >= 1) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        idx /= 2;
    }
}

int get_from_seg(int idx, int s, int e, int ts, int te) {
    if (e < ts || s > te) return 0;
    if (ts <= s && e <= te) return tree[idx];

    int mid = (s + e) / 2;
    int l = get_from_seg(idx * 2, s, mid, ts, te);
    int r = get_from_seg(idx * 2 + 1, mid + 1, e, ts, te);
    return l + r;
}

int main() {
    FASTIO;

    cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        mp[num] = i;
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = mp[num];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += get_from_seg(1, 0, len - 1, arr[i] + 1, n - 1);
        update_seg(arr[i], 1);
    }

    cout << ans << '\n';
    return 0;
}
