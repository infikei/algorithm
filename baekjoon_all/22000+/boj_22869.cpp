// Solve 2022-08-02
// Update 2023-10-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int board[5001];

    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    bool possible[5001] = { false };

    possible[1] = true;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (possible[j] && (i - j) * (1 + abs(board[i] - board[j])) <= k) {
                possible[i] = true;
                break;
            }
        }
    }

    if (possible[n]) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
