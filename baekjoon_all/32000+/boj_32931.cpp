// Solve 2025-09-20

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

int arr[2][200000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    ll memo0 = arr[0][0];
    ll memo1 = -10000000000LL;
    ll memo2 = arr[0][0] + arr[1][0];

    for (int i = 1; i < n; i++) {
        ll tmp0 = max(memo0, memo2) + arr[0][i];
        ll tmp1 = max(memo1, memo2) + arr[1][i];
        ll tmp2 = max(memo0, max(memo1, memo2)) + arr[0][i] + arr[1][i];
        memo0 = tmp0;
        memo1 = tmp1;
        memo2 = tmp2;
    }

    cout << max(memo1, memo2) << '\n';
    return 0;
}
