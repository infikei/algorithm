// Solve 2025-11-04

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

int adj[20001];
bool visited[20001];

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int get_lcm(int a, int b) {
    return a / get_gcd(a, b) * b;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> adj[i];
    }

    int ans = 1;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        int cnt = 0;
        int cur = i;

        while (!visited[cur]) {
            visited[cur] = true;
            cur = adj[cur];
            cnt++;
        }

        ans = get_lcm(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
