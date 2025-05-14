// Solve 2025-05-14

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

int parent[10001];
bool visited[10001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int u = 1; u <= n; u++) {
            visited[u] = false;
        }

        for (int u = 1; u <= n; u++) {
            parent[u] = 0;
        }

        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;

            parent[b] = a;
        }

        int u1, u2;
        cin >> u1 >> u2;

        while (u1 != 0) {
            visited[u1] = true;
            u1 = parent[u1];
        }

        while (!visited[u2]) {
            u2 = parent[u2];
        }

        cout << u2 << '\n';
    }

    return 0;
}
