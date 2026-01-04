// Solve 2025-02-21
// Update 2026-01-03

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

int arr[10000];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> memo;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(memo.begin(), memo.end(), arr[i]);

            if (it == memo.end()) {
                memo.push_back(arr[i]);
            }
            else {
                *it = arr[i];
            }
        }

        cout << "Case #" << ti << '\n';
        cout << (size(memo) >= k) << '\n';
    }

    return 0;
}
