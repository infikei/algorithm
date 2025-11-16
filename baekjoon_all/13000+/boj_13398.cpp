// Solve 2025-11-16

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

int arr[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int memo1[3] = {-INF, -INF, arr[1]};
    int memo2[3] = {-INF, -INF, -INF};
    int mx = arr[1];

    for (int i = 2; i <= n; i++) {
        memo1[0] = memo1[1];
        memo2[0] = memo2[1];
        memo1[1] = memo1[2];
        memo2[1] = memo2[2];
        memo1[2] = max(0, memo1[1]) + arr[i];
        memo2[2] = max(0, max(memo1[0], memo2[1])) + arr[i];
        mx = max(mx, max(memo1[2], memo2[2]));
    }

    cout << mx << '\n';
    return 0;
}
