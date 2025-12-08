// Solve 2025-12-08

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

struct IPhone{
    int x, y, v, p;

    IPhone(int x, int y, int v, int p) : x(x), y(y), v(v), p(p) {
    }
};

int n, k, t;
bool visited[3001];
vector<IPhone> phones;

bool is_in_range(int u, int v) {
    int dx = phones[u].x - phones[v].x;
    int dy = phones[u].y - phones[v].y;
    return dx * dx + dy * dy <= k * k;
}

int main() {
    FASTIO;

    cin >> n >> k >> t;

    {
        int x, y, v;
        cin >> x >> y >> v;
        phones.emplace_back(x, y, v, 0);
    }

    for (int i = 1; i <= n; i++) {
        int x, y, v, p;
        cin >> x >> y >> v >> p;
        phones.emplace_back(x, y, v, p);
    }

    queue<int> que;
    que.push(0);
    visited[0] = true;
    vector<int> ans;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && is_in_range(u, v) && abs(phones[u].v - phones[v].v) <= t) {
                visited[v] = true;
                que.push(v);

                if (phones[v].p) {
                    ans.push_back(v);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << 0 << '\n';
    }
    else {
        for (int u : ans) {
            cout << u << ' ';
        }

        cout << '\n';
    }

    return 0;
}
