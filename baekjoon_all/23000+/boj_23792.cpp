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

int arr[3][100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int x[3], k;
        cin >> x[0] >> x[1] >> x[2] >> k;

        int low = 0;
        int high = 2147483647;
        int mn = 2147483647;

        while (low <= high) {
            int mid = (low + (ll) high) / 2;
            int cnt = 0;

            for (int i = 0; i < 3; i++) {
                cnt += upper_bound(arr[i], arr[i] + x[i], mid) - arr[i];
            }

            if (cnt >= k) {
                mn = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        int idx = 0;
        int jdx = 0;

        for (int i = 0; i < 3; i++) {
            int j = lower_bound(arr[i], arr[i] + x[i], mn) - arr[i];

            if (arr[i][j] == mn) {
                idx = i + 1;
                jdx = j + 1;
                break;
            }
        }

        cout << idx << ' ' << jdx << '\n';
    }

    return 0;
}
