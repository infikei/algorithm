// Solve 2025-11-08

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

int cur[16];
int nxt[16];
vector<int> from[16] = {
    {15},
    {7},
    {11},
    {3, 15},
    {},
    {5},
    {9, 15},
    {1, 7, 11},
    {},
    {6},
    {},
    {2, 7},
    {},
    {},
    {},
    {0, 3, 3, 6, 15}
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        memset(cur, 0, sizeof cur);
        cur[15] = 1;

        int n;
        cin >> n;

        while (n-- > 0) {
            memset(nxt, 0, sizeof nxt);

            for (int x = 0; x < 16; x++) {
                for (int y : from[x]) {
                    nxt[x] += cur[y];
                }
            }

            swap(cur, nxt);
        }

        cout << cur[15] << '\n';
    }

    return 0;
}
