// Solve 2025-11-30

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

vector<int> arr[100010];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;

        while (len-- > 0) {
            int v;
            cin >> v;
            arr[i].push_back(v);
        }

        sort(arr[i].begin(), arr[i].end());
    }

    while (q-- > 0) {
        int a, b, c, j;
        cin >> a >> b >> c >> j;

        auto& aa = arr[a];
        auto& bb = arr[b];
        auto& cc = arr[c];

        int low = 1;
        int high = 1000000000;
        int mn = 1000000000;

        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt1 = upper_bound(aa.begin(), aa.end(), mid) - aa.begin();
            int cnt2 = upper_bound(bb.begin(), bb.end(), mid) - bb.begin();
            int cnt3 = upper_bound(cc.begin(), cc.end(), mid) - cc.begin();
            int cnt = cnt1 + cnt2 + cnt3;

            if (cnt >= j) {
                mn = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << mn << '\n';
    }

    return 0;
}
