// Solve 2023-01-29
// Update 2025-03-03

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

int costs[20][20];
bool removed_routes[20][20];

int floyd_warshall(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                if (costs[j][k] > costs[j][i] + costs[i][k]) {
                    return -1;
                }

                if (costs[j][k] == costs[j][i] + costs[i][k]) {
                    removed_routes[j][k] = true;
                }
            }
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!removed_routes[i][j]) {
                res += costs[i][j];
            }
        }
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }

    int ans = floyd_warshall(n);

    cout << ans << '\n';

    return 0;
}
