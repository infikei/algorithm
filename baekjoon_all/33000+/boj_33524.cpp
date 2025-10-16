// Solve 2025-10-15

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
int a[300000];

int get_board_size(int x) {
    int cnt = upper_bound(a, a + n, x) - a;

    if (cnt == 0) return 0;

    int mx = 0;
    int low = 1;
    int high = 320;

    while (low <= high) {
        int mid = (low + high) / 2;
        int mid_val = 3 * mid * (mid - 1) + 1;

        if (mid_val <= cnt) {
            mx = max(mx, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return mx;
}

int main() {
    FASTIO;

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << get_board_size(x) << ' ';
    }

    cout << '\n';
    return 0;
}
