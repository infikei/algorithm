// Solve 2023-04-28
// Update 2025-03-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

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

        for (int u = 1; u <= n; u++) {
            visited[u] = false;
        }

        int cnt_in_team = 0;

        for (int u = 1; u <= n; u++) {
            if (adj[u] == -1) continue;

            vector<int> vec;
            int cur = u;

            while (true) {
                vec.push_back(cur);
                visited[cur] = true;
                cur = adj[cur];

                if (cur == -1) {
                    while (!vec.empty()) {
                        int back = vec.back();
                        vec.pop_back();
                        visited[back] = false;
                        adj[back] = -1;
                    }

                    break;
                }

                if (visited[cur]) {
                    break;
                }
            }

            while (!vec.empty()) {
                int back = vec.back();
                vec.pop_back();
                visited[back] = false;
                adj[back] = -1;
                cnt_in_team++;

                if (back == cur) {
                    while (!vec.empty()) {
                        int back2 = vec.back();
                        vec.pop_back();
                        visited[back2] = false;
                        adj[back2] = -1;
                    }
                }
            }
        }

        cout << (n - cnt_in_team) << '\n';
    }

    return 0;
}
