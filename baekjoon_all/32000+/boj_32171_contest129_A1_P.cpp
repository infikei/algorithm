// Solve 2024-08-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    cout << (x1 - x0 + y1 - y0) * 2 << '\n';

    for (int i = 1; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        x0 = min(x0, a);
        x1 = max(x1, c);
        y0 = min(y0, b);
        y1 = max(y1, d);

        cout << (x1 - x0 + y1 - y0) * 2 << '\n';
    }

    return 0;
}
