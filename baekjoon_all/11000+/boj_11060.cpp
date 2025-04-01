// Solve 2025-03-31

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

const int MAX = 100000000;

int board[1000];
int memo[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        memo[x] = MAX;
    }

    memo[0] = 0;

    for (int x = 0; x < n; x++) {
        for (int nx = x + 1; nx <= x + board[x]; nx++) {
            memo[nx] = min(memo[nx], memo[x] + 1);
        }
    }

    cout << (memo[n - 1] == MAX ? -1 : memo[n - 1]) << '\n';

    return 0;
}
