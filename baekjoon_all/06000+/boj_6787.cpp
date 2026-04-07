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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int initial = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        initial |= (x << i);
    }

    if (initial == 0) {
        cout << 0 << '\n';
        return 0;
    }

    set<int> visited;
    queue<int> que;
    visited.insert(initial);
    que.push(initial);
    int lev = 0;

    while (!que.empty()) {
        lev++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int j = 0; j < n; j++) {
                if ((cur & (1 << j)) != 0) {
                    continue;
                }

                int nxt = cur | (1 << j);
                int js = j;
                int je = j;

                while (js - 1 >= 0 && (nxt & (1 << (js - 1))) != 0) {
                    js--;
                }

                while (je + 1 < n && (nxt & (1 << (je + 1))) != 0) {
                    je++;
                }

                if (je - js >= 3) {
                    for (int jj = js; jj <= je; jj++) {
                        nxt ^= (1 << jj);
                    }
                }

                if (nxt == 0) {
                    cout << lev << '\n';
                    return 0;
                }

                if (visited.find(nxt) == visited.end()) {
                    visited.insert(nxt);
                    que.push(nxt);
                }
            }
        }
    }

    return 0;
}
