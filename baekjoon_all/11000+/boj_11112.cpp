// Solve 2025-04-03

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
unordered_map<string, int> hs;

void init() {
    queue<string> que;
    hs["12345678#"] = 0;
    que.push("12345678#");
    int dist = 0;

    while (!que.empty()) {
        int iter = que.size();
        dist++;

        while (iter-- > 0) {
            string cur = que.front();
            que.pop();

            int z = 0;

            for (int i = 0; i < 9; i++) {
                if (cur[i] == '#') {
                    z = i;
                    break;
                }
            }

            int x = z / 3;
            int y = z % 3;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

                int nz = nx * 3 + ny;
                string nxt = cur;
                swap(nxt[z], nxt[nz]);

                if (hs.find(nxt) == hs.end()) {
                    hs[nxt] = dist;
                    que.push(nxt);
                }
            }
        }
    }
}

int main() {
    FASTIO;

    init();

    int t;
    cin >> t;

    while (t-- > 0) {
        string board;

        for (int i = 0; i < 3; i++) {
            string row;
            cin >> row;

            board += row;
        }

        if (hs.find(board) == hs.end()) {
            cout << "impossible" << '\n';
        }
        else {
            cout << hs[board] << '\n';
        }
    }

    return 0;
}
