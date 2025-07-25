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
bool selected[100001];

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
        vector<int> path;
        int cnt_in_team = 0;

        for (int u = 1; u <= n; u++) {
            int cur = u;

            while (!selected[cur] && !visited[cur]) {
                selected[cur] = true;
                path.push_back(cur);
                cur = adj[cur];
            }

            if (visited[cur]) {
                while (!path.empty()) {
                    int x = path.back();
                    path.pop_back();
                    selected[x] = false;
                    visited[x] = true;
                }

                continue;
            }

            while (path.back() != cur) {
                int x = path.back();
                path.pop_back();
                selected[x] = false;
                visited[x] = true;
                cnt_in_team++;
            }

            path.pop_back();
            selected[cur] = false;
            visited[cur] = true;
            cnt_in_team++;

            while (!path.empty()) {
                int x = path.back();
                path.pop_back();
                selected[x] = false;
                visited[x] = true;
            }
        }

        cout << n - cnt_in_team << '\n';
    }

    return 0;
}
