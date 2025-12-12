// Solve 2025-12-11

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

int arr[101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    while (m-- > 0) {
        int like, hate;
        cin >> like >> hate;

        int mx = *max_element(arr + 1, arr + (n + 1));

        if (arr[hate] < mx) {
            arr[like]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
    return 0;
}
