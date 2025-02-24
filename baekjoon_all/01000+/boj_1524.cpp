// Solve 2024-11-29
// Update 2025-02-22

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        int max_s = 0;
        int max_b = 0;

        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;

            max_s = max(max_s, s);
        }

        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;

            max_b = max(max_b, b);
        }

        cout << (max_s >= max_b ? 'S' : 'B') << '\n';
    }

    return 0;
}
