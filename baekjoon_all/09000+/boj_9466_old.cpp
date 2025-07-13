// Solve 2023-04-28
// Update 2025-07-13

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

int adj[100001];
bool visited[100001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int u = 1; u <= n; u++) {
            cin >> adj[u];
        }

        memset(visited, 0, sizeof visited);
        int cnt_in_team = 0;

        for (int u = 1; u <= n; u++) {
            if (adj[u] == -1) continue;

            vector<int> path;
            int cur = u;

            while (true) {
                path.push_back(cur);
                visited[cur] = true;
                cur = adj[cur];

                if (cur == -1) {
                    while (!path.empty()) {
                        int back = path.back();
                        path.pop_back();
                        visited[back] = false;
                        adj[back] = -1;
                    }

                    break;
                }

                if (visited[cur]) {
                    break;
                }
            }

            while (!path.empty()) {
                int x = path.back();
                path.pop_back();
                visited[x] = false;
                adj[x] = -1;
                cnt_in_team++;

                if (x == cur) {
                    while (!path.empty()) {
                        int x2 = path.back();
                        path.pop_back();
                        visited[x2] = false;
                        adj[x2] = -1;
                    }
                }
            }
        }

        cout << n - cnt_in_team << '\n';
    }

    return 0;
}
