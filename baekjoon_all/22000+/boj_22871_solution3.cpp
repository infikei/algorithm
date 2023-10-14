// Solve 2022-08-02
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<ll> board(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    vector<bool> possible;

    ll low = 0, high = (n - 1) * (1 + abs(board[n] - board[1]));

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        possible.assign(n + 1, false);

        possible[1] = true;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (possible[j] && (i - j) * (1 + abs(board[i] - board[j])) <= mid) {
                    possible[i] = true;
                    break;
                }
            }
        }

        if (possible[n]) high = mid;
        else low = mid;
    }

    cout << high << '\n';

    return 0;
}
