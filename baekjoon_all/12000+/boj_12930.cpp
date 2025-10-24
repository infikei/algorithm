// Solve 2025-10-24

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

struct AdjNode{
    int to, w1, w2;

    AdjNode(int to, int w1, int w2) : to(to), w1(w1), w2(w2) {
    }
};

int w1_board[20][20];
int w2_board[20][20];
int memo[20];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        string line;
        cin >> line;

        for (int y = 0; y < n; y++) {
            w1_board[x][y] = (line[y] == '.' ? INF : line[y] - '0');
        }
    }

    for (int x = 0; x < n; x++) {
        string line;
        cin >> line;

        for (int y = 0; y < n; y++) {
            w2_board[x][y] = (line[y] == '.' ? INF : line[y] - '0');
        }
    }

    auto cmp = [](const AdjNode& a, const AdjNode& b) {
        if (a.w1 != b.w1) return a.w1 > b.w1;
        return a.w2 > b.w2;
    };

    priority_queue<AdjNode, vector<AdjNode>, decltype(cmp)> pq(cmp);
    memset(memo, 0x3f, sizeof memo);
    pq.emplace(0, 0, 0);
    int mn = INF;

    while (!pq.empty()) {
        AdjNode cur = pq.top();
        pq.pop();

        if (memo[cur.to] <= cur.w2) continue;
        if (cur.to == 1) {
            mn = min(mn, cur.w1 * cur.w2);
        }

        memo[cur.to] = cur.w2;

        for (int nxt = 0; nxt < n; nxt++) {
            if (w1_board[cur.to][nxt] == INF) continue;

            int nw1 = cur.w1 + w1_board[cur.to][nxt];
            int nw2 = cur.w2 + w2_board[cur.to][nxt];

            if (memo[nxt] > nw2) {
                pq.emplace(nxt, nw1, nw2);
            }
        }
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}
