// Solve 2026-03-25

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

struct PointDist{
    int x, y;
    ll d;

    PointDist(int x, int y, ll d) : x(x), y(y), d(d) {
    }
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;
    vector<PointDist> cur;
    cur.emplace_back(x, y, 0);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        vector<PointDist> nxt;

        for (int d = 0; d < 5; d++) {
            nxt.emplace_back(x + dx[d], y + dy[d], LLINF);
        }

        for (auto& u : cur) {
            for (auto& v : nxt) {
                v.d = min(v.d, u.d + abs(u.x - v.x) + abs(u.y - v.y));
            }
        }

        swap(cur, nxt);
    }

    ll mn = LLINF;

    for (auto& u : cur) {
        mn = min(mn, u.d);
    }

    cout << mn << '\n';
    return 0;
}
