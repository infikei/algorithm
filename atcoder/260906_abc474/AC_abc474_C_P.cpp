// Solve 2026-09-06

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

int idx[200001];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        idx[x] = i;
    }

    for (int i = n + 1; i <= n + q; i++) {
        int x;
        cin >> x;
        idx[x] = i;
    }

    vector<pii> v;

    for (int x = 1; x <= n; x++) {
        v.emplace_back(idx[x], x);
    }

    sort(v.begin(), v.end());

    for (pii& p : v) {
        cout << p.second << ' ';
    }

    cout << '\n';
    return 0;
}
