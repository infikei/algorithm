// Solve 2025-11-06

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

struct AdjEdge{
    int to, capa, flow, rev;

    AdjEdge(int to, int capa, int flow, int rev) : to(to), capa(capa), flow(flow), rev(rev) {
    }
};

string board[100];
vector<AdjEdge> adj[20000];
int level[20000];
int adj_pos[20000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void add_edge(int u, int v, int w) {
    adj[u].emplace_back(v, w, 0, size(adj[v]));
    adj[v].emplace_back(u, 0, 0, size(adj[u]) - 1);
}

bool dinic_bfs(int s, int t) {
    queue<int> que;
    memset(level, -1, sizeof level);
    que.push(s);
    level[s] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (AdjEdge& e : adj[cur]) {
            int nxt = e.to;

            if (level[nxt] == -1 && e.capa > e.flow) {
                level[nxt] = level[cur] + 1;
                que.push(nxt);
            }
        }
    }

    return level[t] != -1;
}

int dinic_dfs(int cur, int t, int cur_flow) {
    if (cur == t) return cur_flow;

    for (int& i = adj_pos[cur]; i < size(adj[cur]); i++) {
        AdjEdge& e = adj[cur][i];
        int nxt = e.to;

        if (level[nxt] == level[cur] + 1 && e.capa > e.flow) {
            int fl = dinic_dfs(nxt, t, min(cur_flow, e.capa - e.flow));

            if (fl > 0) {
                e.flow += fl;
                adj[nxt][e.rev].flow -= fl;
                return fl;
            }
        }
    }

    return 0;
}

int dinic(int s, int t) {
    int ret = 0;

    while (dinic_bfs(s, t)) {
        memset(adj_pos, 0, sizeof adj_pos);

        while (true) {
            int fl = dinic_dfs(s, t, INF);
            ret += fl;

            if (fl == 0) break;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int s = 0;
    int t = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == '#') continue;

            int u = x * 100 + y; // (x, y)의 정점 번호
            int u_in = u * 2;
            int u_out = u * 2 + 1;

            if (board[x][y] == '.') {
                // 정점 분할 후 in 정점 -> out 정점 간선 연결
                add_edge(u_in, u_out, 1);
            }
            else if (board[x][y] == 'K') {
                // 집을 시작 정점으로 설정
                s = u_out;

                // 집과 학교가 인접한다면 -1 출력 후 종료
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'H') {
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            }
            else if (board[x][y] == 'H') {
                // 학교를 끝 정점으로 설정
                t = u_in;
            }

            // 오른쪽 및 아래로 인접한 빈 칸이 있다면 간선 연결
            for (int d = 0; d < 2; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= n || ny >= m || board[nx][ny] == '#') continue;

                int v = nx * 100 + ny; // (nx, ny)의 정점 번호
                int v_in = v * 2;
                int v_out = v * 2 + 1;

                add_edge(u_out, v_in, 1); // u -> v 간선 연결
                add_edge(v_out, u_in, 1); // v -> u 간선 연결
            }
        }
    }

    cout << dinic(s, t) << '\n';
    return 0;
}
