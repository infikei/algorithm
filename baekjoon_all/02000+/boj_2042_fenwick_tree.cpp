// Solve 2022-12-09
// Update 2025-10-27

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
ll arr[1000001];
ll fenwick[1000001];

void update_fenwick(int idx, ll diff) {
    while (idx <= n) {
        fenwick[idx] += diff;
        idx += (idx & -idx);
    }
}

ll get_from_fenwick(int idx) {
    ll ret = 0;

    while (idx >= 1) {
        ret += fenwick[idx];
        idx -= (idx & -idx);
    }

    return ret;
}

int main() {
    FASTIO;

    int m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update_fenwick(i, arr[i]);
    }

    int q = m + k;

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int b;
            ll c;
            cin >> b >> c;
            update_fenwick(b, c - arr[b]);
            arr[b] = c;
        }
        else {
            int b, c;
            cin >> b >> c;
            cout << get_from_fenwick(c) - get_from_fenwick(b - 1) << '\n';
        }
    }

    return 0;
}
