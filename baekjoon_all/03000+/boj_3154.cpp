// Solve 2025-01-18
// Update 2025-09-23

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

pii keyboard[10] = {
    {3, 1},
    {0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2}
};

int get_dist(pii& p1, pii& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    FASTIO;

    string hhmm;
    cin >> hhmm;

    int h = stoi(hhmm.substr(0, 2));
    int m = stoi(hhmm.substr(3, 2));
    int min_effort_h = h;
    int min_effort_m = m;
    int min_effort = INF;

    for (int i = h; i < 100; i += 24) {
        int d1 = i / 10;
        int d2 = i % 10;

        for (int j = m; j < 100; j += 60) {
            int d3 = j / 10;
            int d4 = j % 10;
            int effort = get_dist(keyboard[i / 10], keyboard[i % 10])
                    + get_dist(keyboard[i % 10], keyboard[j / 10])
                    + get_dist(keyboard[j / 10], keyboard[j % 10]);

            if (effort < min_effort) {
                min_effort = effort;
                min_effort_h = i;
                min_effort_m = j;
            }
        }
    }

    cout << setw(2) << setfill('0') << min_effort_h << ':';
    cout << setw(2) << setfill('0') << min_effort_m << '\n';
    return 0;
}
