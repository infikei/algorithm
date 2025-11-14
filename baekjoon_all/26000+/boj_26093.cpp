// Solve 2025-11-13

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

    int n, k;
    cin >> n >> k;

    pii cur1 = {0, 0};
    pii cur2 = {0, 1};

    for (int i = 0; i < n; i++) {
        pii nxt1 = {0, 0};
        pii nxt2 = {0, 0};

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            pii tmp;

            if (j == cur1.second) {
                tmp = {cur2.first + v, j};
            }
            else {
                tmp = {cur1.first + v, j};
            }

            if (tmp > nxt1) {
                nxt2 = nxt1;
                nxt1 = tmp;
            }
            else if (tmp > nxt2) {
                nxt2 = tmp;
            }
        }

        cur1 = nxt1;
        cur2 = nxt2;
    }

    cout << cur1.first << '\n';
    return 0;
}
