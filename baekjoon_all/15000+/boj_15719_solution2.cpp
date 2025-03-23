// Solve 2025-03-21

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

    int n;
    cin >> n;

    int tmp = 0;

    for (int i = (n - 1) / 4 * 4; i <= n - 1; i++) {
        tmp ^= i;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        tmp ^= x;
    }

    cout << tmp << '\n';

    return 0;
}
