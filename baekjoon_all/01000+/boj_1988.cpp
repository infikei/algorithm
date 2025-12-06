// Solve 2025-12-03

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

int n;
int arr[3000];
int memo[2][3000][3001];

int f(int depth, int b, int prv) {
    if (b == 0) return 0;
    if (depth == n) return 0;
    if (memo[prv][depth][b] != -1) return memo[prv][depth][b];

    int nxt1 = f(depth + 1, b - 1, 1) + (prv == 1 ? arr[depth] : 0);
    int nxt2 = f(depth + 1, b, 0);
    return memo[prv][depth][b] = max(nxt1, nxt2);
}

int main() {
    FASTIO;
    memset(memo, -1, sizeof memo);

    int b;
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << f(0, b, 0) << '\n';
    return 0;
}
