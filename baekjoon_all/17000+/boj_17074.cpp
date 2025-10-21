// Solve 2025-10-20

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

int arr[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int desc_cnt = 0;
    int desc_idx = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            desc_cnt++;
            desc_idx = i;

            if (desc_cnt == 2) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    if (desc_cnt == 0) {
        cout << n << '\n';
        return 0;
    }

    int ans = 0;

    if (desc_idx - 2 < 0 || arr[desc_idx - 2] <= arr[desc_idx]) {
        ans++;
    }

    if (desc_idx + 1 >= n || arr[desc_idx - 1] <= arr[desc_idx + 1]) {
        ans++;
    }

    cout << ans << '\n';
    return 0;
}
