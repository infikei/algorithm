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

int arr[100002];
bool prefix[100002];
bool suffix[100002];

int main() {
    FASTIO;

    int n;
    cin >> n;

    arr[0] = -INF;
    arr[n + 1] = INF;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    prefix[0] = true;
    suffix[n + 1] = true;

    for (int i = 1; i <= n; i++) {
        if (arr[i - 1] > arr[i]) break;

        prefix[i] = true;
    }

    for (int i = n; i >= 1; i--) {
        if (arr[i] > arr[i + 1]) break;

        suffix[i] = true;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (prefix[i - 1] && suffix[i + 1] && arr[i - 1] <= arr[i + 1]) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
