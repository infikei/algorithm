// Solve 2026-02-24

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

bool sieve[10000];
bool visited[10000];

void create_sieve() {
    sieve[1] = true;

    for (int i = 2; i * i < 10000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j < 10000; j += i) {
            sieve[j] = true;
        }
    }
}

int bfs(int a, int b) {
    if (a == b) return 0;

    memset(visited, false, sizeof(visited));

    queue<int> que;
    que.push(a);
    visited[a] = true;
    int depth = 0;

    while (!que.empty()) {
        depth++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int d = 0; d < 10; d++) {
                int nxt_arr[4] = {
                    d * 1000 + cur % 1000,
                    cur / 1000 * 1000 + d * 100 + cur % 100,
                    cur / 100 * 100 + d * 10 + cur % 10,
                    cur / 10 * 10 + d
                };

                for (int nxt : nxt_arr) {
                    if (nxt == b) return depth;

                    if (nxt >= 1000 && !visited[nxt] && !sieve[nxt]) {
                        visited[nxt] = true;
                        que.push(nxt);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    create_sieve();

    int t;
    cin >> t;

    while (t-- > 0) {
        int a, b;
        cin >> a >> b;

        int ans = bfs(a, b);

        if (ans == -1) {
            cout << "impossible" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
