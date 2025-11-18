// Solve 2025-11-18

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

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    unordered_map<int, int> imos;
    imos[1] = 2 * n;

    for (int i = 1; i < n; i++) {
        int gap = arr[i] - arr[i - 1] - 1;

        if (gap % 2 == 0) {
            imos[gap / 2 + 1] -= 2;
        }
        else {
            imos[gap / 2 + 1]--;
            imos[gap / 2 + 2]--;
        }
    }

    ll ans = 0;
    int level = 0;
    int prefix_sum = 0;

    while (k > 0) {
        level++;
        prefix_sum += imos[level];

        ans += level * min(k, prefix_sum);
        k -= prefix_sum;
    }

    cout << ans << '\n';
    return 0;
}
