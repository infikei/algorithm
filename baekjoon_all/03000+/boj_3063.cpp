// Solve 2026-02-18

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

int x[4];
int y[4];
int sorted_x[4];
int sorted_y[4];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
            sorted_x[i] = x[i];
            sorted_y[i] = y[i];
        }

        sort(sorted_x, sorted_x + 4);
        sort(sorted_y, sorted_y + 4);
        int area = 0;

        for (int i = 0; i < 3; i++) {
            if (x[0] <= sorted_x[i] && sorted_x[i + 1] <= x[1]) {
                for (int j = 0; j < 3; j++) {
                    if (y[0] <= sorted_y[j] && sorted_y[j + 1] <= y[1]) {
                        if (sorted_x[i + 1] <= x[2] || x[3] <= sorted_x[i] || sorted_y[j + 1] <= y[2] || y[3] <= sorted_y[j]) {
                            area += (sorted_x[i + 1] - sorted_x[i]) * (sorted_y[j + 1] - sorted_y[j]);
                        }
                    }
                }
            }
        }

        cout << area << '\n';
    }

    return 0;
}
