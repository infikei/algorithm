// Solve 2022-07-23
// Update 2025-11-17

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
int board[20][20];
bool selected[20];
int mn = INF;

int get_score(bool team) {
    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (selected[i] != team) continue;

        for (int j = i + 1; j < n; j++) {
            if (selected[j] != team) continue;

            ret += board[i][j] + board[j][i];
        }
    }

    return ret;
}

void recur(int depth, int idx_begin) {
    if (depth == n / 2) {
        mn = min(mn, abs(get_score(true) - get_score(false)));
        return;
    }

    for (int i = idx_begin; i < n; i++) {
        selected[i] = true;
        recur(depth + 1, i + 1);
        selected[i] = false;
    }
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    selected[0] = true; // 0번 사람은 true 팀으로 고정
    recur(1, 1);
    cout << mn << '\n';
    return 0;
}
