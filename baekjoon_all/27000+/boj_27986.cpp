// Solve 2023-08-24
// Update 2025-02-26

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

    int n, m;
    cin >> n >> m;

    int k = n;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        k = min(k, e - s + 1);
    }

    for (int i = 0; i < n; i++) {
        cout << i % k + 1 << ' ';
    }

    cout << '\n';

    return 0;
}
