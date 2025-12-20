// Solve 2023-02-10
// Update 2025-12-17

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

int n, w;
pii points[1001];
int memo[1001][1001];

int get_dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int recur(int a, int b) {
    int cur = max(a, b) + 1;

    if (cur > w) return 0;
    if (memo[a][b] != -1) return memo[a][b];

    int x = recur(cur, b);
    x += get_dist(points[cur], (a == 0 ? pii(1, 1) : points[a]));

    int y = recur(a, cur);
    y += get_dist(points[cur], (b == 0 ? pii(n, n) : points[b]));

    return memo[a][b] = min(x, y);
}

void find_path(int a, int b) {
    int cur = max(a, b) + 1;

    if (cur > w) return;

    int x = recur(cur, b);
    x += get_dist(points[cur], (a == 0 ? pii(1, 1) : points[a]));

    if (memo[a][b] == x) {
        cout << 1 << '\n';
        find_path(cur, b);
    }
    else {
        cout << 2 << '\n';
        find_path(a, cur);
    }
}

int main() {
    FASTIO;

    cin >> n >> w;

    for (int i = 1; i <= w; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    memset(memo, -1, sizeof memo);
    cout << recur(0, 0) << '\n';
    find_path(0, 0);
    return 0;
}
