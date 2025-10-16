// Solve 2025-10-14

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

int a[1000001];
int b[1000001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[v]++;
    }

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        b[v]++;
    }

    int matching_cnt = 0;

    for (int u = 1; u <= 1000000; u++) {
        matching_cnt += min(a[u], b[u]);
    }

    cout << n - matching_cnt << '\n';
    return 0;
}
