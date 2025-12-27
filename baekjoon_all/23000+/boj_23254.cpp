// Solve 2025-12-27

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

int a[200000];
int b[200000];
int cnt[101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int score = 0;

    for (int i = 0; i < m; i++) {
        score += a[i];

        int x = 100 - a[i];
        int q = x / b[i];
        int r = x % b[i];

        cnt[b[i]] += q;
        cnt[r]++;
    }

    n *= 24;

    for (int i = 100; i >= 1; i--) {
        int x = min(n, cnt[i]);
        n -= x;
        score += x * i;
    }

    cout << score << '\n';
    return 0;
}
