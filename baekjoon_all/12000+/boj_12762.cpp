// Solve 2025-10-09

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

int arr[1000];
int lds[1000]; // Longest Decreasing Subsequence
int rlds[1000]; // Reversed LDS

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> memo;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(memo.begin(), memo.end(), arr[i], greater<int>());

        if (it == memo.end()) {
            memo.push_back(arr[i]);
            lds[i] = size(memo);
        }
        else {
            *it = arr[i];
            lds[i] = (it - memo.begin()) + 1;
        }
    }

    memo.clear();

    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(memo.begin(), memo.end(), arr[i], greater<int>());

        if (it == memo.end()) {
            memo.push_back(arr[i]);
            rlds[i] = size(memo);
        }
        else {
            *it = arr[i];
            rlds[i] = (it - memo.begin()) + 1;
        }
    }

    int mx = 1;

    for (int i = 0; i < n; i++) {
        mx = max(mx, lds[i] + rlds[i] - 1);
    }

    cout << mx << '\n';
    return 0;
}
