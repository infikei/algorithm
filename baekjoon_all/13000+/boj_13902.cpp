// Solve 2026-03-31

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
int arr2[10001];
int memo[10001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        arr2[arr[i]] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] > 10000) continue;

            arr2[arr[i] + arr[j]] = 1;
        }
    }

    memset(memo, 0x3f, sizeof(memo));

    for (int i = 1; i <= n; i++) {
        if (arr2[i] == 1) {
            memo[i] = 1;
        }

        for (int j = i / 2; j >= 1; j--) {
            memo[i] = min(memo[i], memo[j] + memo[i - j]);
        }
    }

    if (memo[n] == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << memo[n] << '\n';
    }

    return 0;
}
