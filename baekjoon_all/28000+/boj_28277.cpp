// Solve 2025-11-09

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

set<int> st[500001];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int u = 1; u <= n; u++) {
        int iter;
        cin >> iter;

        while (iter-- > 0) {
            int x;
            cin >> x;
            st[u].insert(x);
        }
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int a, b;
            cin >> a >> b;

            if (size(st[a]) > size(st[b])) {
                for (auto x : st[b]) {
                    st[a].insert(x);
                }

                // st[b].clear();
                set<int> tmp;
                swap(st[b], tmp);
            }
            else {
                for (auto x : st[a]) {
                    st[b].insert(x);
                }

                // st[a].clear();
                set<int> tmp;
                swap(st[a], tmp);

                swap(st[a], st[b]);
            }
        }
        else {
            int a;
            cin >> a;
            cout << size(st[a]) << '\n';
        }
    }

    return 0;
}
