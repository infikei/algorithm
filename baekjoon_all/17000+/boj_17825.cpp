// Solve 2025-10-21

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

vector<vector<int>> adj(33, vector<int>(6));
int scores[33] = {
    0, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    40, 0, 13, 16, 19,
    22, 24, 28, 27, 26,
    25, 30, 35
};
int dice[10];
int mx;

void init_adj() {
    for (int u = 0; u <= 16; u++) {
        for (int i = 0; i <= 5; i++) {
            adj[u][i] = u + i;
        }
    }

    adj[5] = {5, 22, 23, 24, 30, 31};
    adj[10] = {10, 25, 26, 30, 31, 32};
    adj[15] = {15, 27, 28, 29, 30, 31};
    adj[17] = {17, 18, 19, 20, 21, 21};
    adj[18] = {18, 19, 20, 21, 21, 21};
    adj[19] = {19, 20, 21, 21, 21, 21};
    adj[20] = {20, 21, 21, 21, 21, 21};
    adj[21] = {21, 21, 21, 21, 21, 21};
    adj[22] = {22, 23, 24, 30, 31, 32};
    adj[23] = {23, 24, 30, 31, 32, 20};
    adj[24] = {24, 30, 31, 32, 20, 21};
    adj[25] = {25, 26, 30, 31, 32, 20};
    adj[26] = {26, 30, 31, 32, 20, 21};
    adj[27] = {27, 28, 29, 30, 31, 32};
    adj[28] = {28, 29, 30, 31, 32, 20};
    adj[29] = {29, 30, 31, 32, 20, 21};
    adj[30] = {30, 31, 32, 20, 21, 21};
    adj[31] = {31, 32, 20, 21, 21, 21};
    adj[32] = {32, 20, 21, 21, 21, 21};
}

void recur(int depth, vector<int> pos, int score) {
    if (depth == 10) {
        mx = max(mx, score);
        return;
    }

    sort(pos.begin(), pos.end());

    for (int i = 0; i < 4; i++) {
        if (i >= 1 && pos[i - 1] == pos[i]) continue;

        vector<int> nxt_pos = pos;
        nxt_pos[i] = adj[nxt_pos[i]][dice[depth]];
        bool valid = true;

        if (nxt_pos[i] != 21) {
            for (int j = 0; j < 4; j++) {
                if (i != j && nxt_pos[i] == nxt_pos[j]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            recur(depth + 1, nxt_pos, score + scores[nxt_pos[i]]);
        }
    }
}

int main() {
    FASTIO;

    init_adj();

    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }

    vector<int> pos(4, 0);
    recur(0, pos, 0);
    cout << mx << '\n';
    return 0;
}
