// Solve 2025-04-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int n, m, k;
int board[257][257];
int memo[257];

void init_memo() {
    for (int i = 0; i < 257; i++) {
        memo[i] = 0;
    }
}

void add_row_to_memo(int x) {
    for (int y = 1; y <= m; y++) {
        memo[y] = (memo[y] + board[x][y]) % k;
    }
}

int count_with_memo() {
    map<int, int> mp;
    mp[0]++;
    int res = 0;

    for (int y = 1; y <= m; y++) {
        res += mp[memo[y]];
        mp[memo[y]]++;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> n >> m >> k;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            board[x][y] += board[x][y - 1];
        }
    }

    int cnt = 0;

    for (int x1 = 1; x1 <= n; x1++) {
        init_memo();

        for (int x2 = x1; x2 <= n; x2++) {
            add_row_to_memo(x2);
            cnt += count_with_memo();
        }
    }

    cout << cnt << '\n';

    return 0;
}
