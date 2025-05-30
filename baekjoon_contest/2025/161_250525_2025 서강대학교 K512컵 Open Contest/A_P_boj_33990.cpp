// Solve 2025-05-25

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
    int ans = 1000000000;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int s = a + b + c;

        if (s >= 512) {
            ans = min(ans, s);
        }
    }

    cout << (ans == 1000000000 ? -1 : ans) << '\n';

    return 0;
}
