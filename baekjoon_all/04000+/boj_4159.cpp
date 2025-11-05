// Solve 2025-11-05

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

int n;
int arr[2000];

bool check() {
    if (arr[0] > 200 || arr[n - 1] < 1322) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > 200) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    while (true) {
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        cout << (check() ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }

    return 0;
}
