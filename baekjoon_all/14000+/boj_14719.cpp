// Solve 2024-11-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int heights[500];

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    for (int x = 0; x < w; x++) {
        cin >> heights[x];
    }

    int max_height = 0;
    int max_height_first_x = 0;
    int max_height_last_x = 0;

    for (int x = 0; x < w; x++) {
        if (heights[x] > max_height) {
            max_height = heights[x];
            max_height_first_x = x;
            max_height_last_x = x;
        }
        else if (heights[x] == max_height) {
            max_height_last_x = x;
        }
    }

    int ans = 0;
    int prev_max_height = 0;

    for (int x = 0; x < max_height_last_x; x++) {
        if (heights[x] <= prev_max_height) {
            ans += prev_max_height - heights[x];
        }
        else {
            prev_max_height = heights[x];
        }
    }

    prev_max_height = 0;

    for (int x = w - 1; x > max_height_last_x; x--) {
        if (heights[x] <= prev_max_height) {
            ans += prev_max_height - heights[x];
        }
        else {
            prev_max_height = heights[x];
        }
    }

    println(ans);

    return 0;
}
