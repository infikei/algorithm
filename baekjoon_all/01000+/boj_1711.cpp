// Solve 2025-06-07

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
using pll = pair<ll, ll>;

pll points[1500];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        ll x1 = points[i].first;
        ll y1 = points[i].second;

        for (int j = i + 1; j < n; j++) {
            ll x2 = points[j].first;
            ll y2 = points[j].second;
            ll d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

            for (int k = j + 1; k < n; k++) {
                ll x3 = points[k].first;
                ll y3 = points[k].second;
                ll d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
                ll d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);

                if (d1 + d2 == d3 || d2 + d3 == d1 || d3 + d1 == d2) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
