// Solve 2022-08-12
// Update 2025-09-28

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

int bfs(int a, int b) {
    queue<int> que;
    que.push(a);
    int depth = 1;

    while (!que.empty()) {
        depth++;
        int iter = size(que);

        while (iter-- > 0) {
            ll cur = que.front();
            que.pop();

            ll nxt = cur * 2;

            if (nxt < b) {
                que.push(nxt);
            }
            else if (nxt == b) {
                return depth;
            }

            nxt = cur * 10 + 1;

            if (nxt < b) {
                que.push(nxt);
            }
            else if (nxt == b) {
                return depth;
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << '\n';
    return 0;
}
