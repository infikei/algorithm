// Solve 2024-11-02
// Update 2025-10-04

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

int heights[500];

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    for (int x = 0; x < w; x++) {
        cin >> heights[x];
    }

    int max_h = 0;
    int left_of_max_h = 0;
    int right_of_max_h = 0;

    for (int x = 0; x < w; x++) {
        if (heights[x] > max_h) {
            max_h = heights[x];
            left_of_max_h = x;
            right_of_max_h = x;
        }
        else if (heights[x] == max_h) {
            right_of_max_h = x;
        }
    }

    int ans = 0;
    max_h = 0;

    for (int x = 0; x < right_of_max_h; x++) {
        if (heights[x] <= max_h) {
            ans += max_h - heights[x];
        }
        else {
            max_h = heights[x];
        }
    }

    max_h = 0;

    for (int x = w - 1; x > right_of_max_h; x--) {
        if (heights[x] <= max_h) {
            ans += max_h - heights[x];
        }
        else {
            max_h = heights[x];
        }
    }

    cout << ans << '\n';
    return 0;
}
