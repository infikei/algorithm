// Solve 2025-10-18

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

int adj[17][100001];
int s[100001];

bool is_all_night(map<int, int>& mp, int k) {
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second >= k) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int u = 1; u <= n; u++) {
        cin >> adj[0][u];
    }

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        mp[u]++;
    }

    for (int i = 1; i < 17; i++) {
        for (int u = 1; u <= n; u++) {
            adj[i][u] = adj[i - 1][adj[i - 1][u]];
        }
    }

    int mn = INF;
    int low = 0;
    int high = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        map<int, int> n_mp;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int nxt = it->first;

            for (int i = 16; i >= 0; i--) {
                if (mid & (1 << i)) {
                    nxt = adj[i][nxt];
                }
            }

            n_mp[nxt] += it->second;
        }

        if (is_all_night(n_mp, k)) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << (mn == INF ? -1 : mn + 1) << '\n';
    return 0;
}
