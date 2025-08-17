// Solve 2025-08-14

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

bool prime_sieve[2001];
vector<int> adj[50];
int matching[50];
bool visited[50];

void init_sieve() {
    for (int i = 2; i <= 2000; i++) {
        prime_sieve[i] = true;
    }

    for (int i = 2; i <= 2000; i++) {
        if (!prime_sieve[i]) continue;

        for (int j = i * 2; j <= 2000; j += i) {
            prime_sieve[j] = false;
        }
    }
}

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (matching[v] == -1 || dfs(matching[v])) {
            matching[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;
    init_sieve();

    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        if (a[0] % 2 == x % 2) {
            a.push_back(x);
        }
        else {
            b.push_back(x);
        }
    }

    for (int u = 0; u < size(a); u++) {
        for (int v = 0; v < size(b); v++) {
            if (prime_sieve[a[u] + b[v]]) {
                adj[u].push_back(v);
            }
        }
    }

    vector<int> ans;

    for (int v : adj[0]) {
        int removed_b_idx = v;
        memset(matching, -1, sizeof matching);
        int matching_cnt = 2;

        for (int u = 1; u < size(a); u++) {
            memset(visited, false, sizeof visited);
            visited[removed_b_idx] = true;

            if (dfs(u)) {
                matching_cnt += 2;
            }
        }

        if (matching_cnt == n) {
            ans.push_back(b[v]);
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    sort(ans.begin(), ans.end());

    for (int& x : ans) {
        cout << x << ' ';
    }

    cout << '\n';
    return 0;
}
