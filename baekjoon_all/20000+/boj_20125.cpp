// Solve 2025-10-29

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
string board[1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pii find_head() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == '*') {
                return {x, y};
            }
        }
    }

    return {-1, -1};
}

int get_len(int x, int y, int d) {
    int ret = 0;

    while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == '*') {
        ret++;
        x += dx[d];
        y += dy[d];
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    pii head = find_head();
    pii heart = {head.first + 1, head.second};
    int left_arm = get_len(heart.first, heart.second - 1, 3);
    int right_arm = get_len(heart.first, heart.second + 1, 1);
    int waist = get_len(heart.first + 1, heart.second, 2);
    int left_leg = get_len(heart.first + waist + 1, heart.second - 1, 2);
    int right_leg = get_len(heart.first + waist + 1, heart.second + 1, 2);

    cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
    cout << left_arm << ' ' << right_arm << ' ' << waist << ' ' << left_leg << ' ' << right_leg << '\n';
    return 0;
}
