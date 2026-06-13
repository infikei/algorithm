// Solve 2026-06-13

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> gift(n + 1);

    for (int u = 1; u <= n; u++) {
        int k;
        cin >> k;

        while (k--  > 0) {
            int v;
            cin >> v;
            gift[v].push_back(u);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << size(gift[u]) << ' ';

        for (int v : gift[u]) {
            cout << v << ' ';
        }

        cout << '\n';
    }

    return 0;
}
