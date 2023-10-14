// Solve 2022-08-02
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll board[5001];
bool possible[5001];
int n;

bool search(ll k, int now = 1) {
    if (now == n) return true;

    for (int next = now + 1; next <= n; next++) {
        if (!possible[next] && (next - now) * (1 + abs(board[now] - board[next])) <= k) {
            possible[next] = true;

            if (search(k, next)) return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    ll low = 0, high = (n - 1) * (1 + abs(board[n] - board[1]));

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        possible[1] = true;

        for (int i = 2; i <= n; i++) {
            possible[i] = false;
        }

        if (search(mid)) high = mid;
        else low = mid;
    }

    cout << high << '\n';

    return 0;
}
