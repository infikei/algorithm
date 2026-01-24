// Solve 2026-01-20

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
string s;
int memo[5000];

int recur(int depth) {
    if (depth >= n) return 0;
    if (s[depth] == '0') return INF;
    if (memo[depth] != -1) return memo[depth];

    int ret = INF;

    if (depth + 2 < n && stoi(s.substr(depth, 3)) <= 641) {
        ret = min(ret, recur(depth + 3) + 1);
    }

    if (depth + 1 < n) {
        ret = min(ret, recur(depth + 2) + 1);
    }

    ret = min(ret, recur(depth + 1) + 1);
    memo[depth] = ret;
    return ret;
}

int main() {
    FASTIO;

    cin >> n >> s;

    memset(memo, -1, sizeof(memo));
    cout << recur(0) << '\n';
    return 0;
}
