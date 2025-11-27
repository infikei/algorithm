// Solve 2025-11-27

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

int arr[3001];
ll memo[3001][3001];
int pos[1000001];

int main() {
    FASTIO;

    int n;
    cin >> n;
    ll mx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int v = arr[j] * 2 - arr[i];
            int k = v >= 0 ? pos[v] : 0;

            if (k > 0) {
                memo[j][i] = memo[k][j] + arr[i];
                mx = max(mx, memo[j][i]);
            }
            else {
                memo[j][i] = arr[j] + arr[i];
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
