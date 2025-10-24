// Solve 2025-10-24

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

int a[10000];
int b[10000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n, greater<int>());
    sort(b, b + m, greater<int>());
    int cnt = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && a[i] <= b[j]) {
            j++;
        }

        if (j < m) {
            cnt++;
            j++;
        }
    }

    cout << cnt + n << '\n';
    return 0;
}
