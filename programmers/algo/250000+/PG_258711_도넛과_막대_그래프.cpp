// Solve 2025-10-08

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    const int MAX_NODE_NUM = 1000000;

    // 간선 리스트로 변환
    vector<vector<int>> adj(MAX_NODE_NUM + 1); // 나가는 간선
    vector<vector<int>> radj(MAX_NODE_NUM + 1); // 들어오는 간선

    for (vector<int>& edge : edges) {
        int u1 = edge[0];
        int u2 = edge[1];
        adj[u1].push_back(u2);
        radj[u2].push_back(u1);
    }

    // 생성한 정점 번호 찾기
    int created_node = 0;

    for (int u = 1; u <= MAX_NODE_NUM; u++) {
        if (size(radj[u]) == 0 && size(adj[u]) >= 2) {
            created_node = u;
            break;
        }
    }

    // 각 그래프의 수 구하기
    // (생성한 정점에 연결된 정점마다 하나의 그래프 존재)
    vector<bool> visited(MAX_NODE_NUM + 1);
    visited[created_node] = true;
    int graph_cnt[3] = {0};

    for (int u : adj[created_node]) {
        int node_cnt = 0;
        int edge_cnt = 0;
        queue<int> bfs_que;
        bfs_que.push(u);
        visited[u] = true;

        while (!bfs_que.empty()) {
            int cur = bfs_que.front();
            bfs_que.pop();
            node_cnt++;
            edge_cnt += size(adj[cur]);

            // 현재 정점에서 나가는 간선 탐색
            for (int nxt : adj[cur]) {
                if (visited[nxt]) continue;

                visited[nxt] = true;
                bfs_que.push(nxt);
            }

            // 현재 정점으로 들어오는 간선 탐색
            for (int nxt : radj[cur]) {
                if (visited[nxt]) continue;

                visited[nxt] = true;
                bfs_que.push(nxt);
            }
        }

        // 도넛 모양 그래프
        if (node_cnt == edge_cnt) {
            graph_cnt[0]++;
        }
        // 막대 모양 그래프
        else if (node_cnt == edge_cnt + 1) {
            graph_cnt[1]++;
        }
        // 8자 모양 그래프
        else if (node_cnt + 1 == edge_cnt) {
            graph_cnt[2]++;
        }
    }

    vector<int> ans;
    ans.push_back(created_node);
    ans.push_back(graph_cnt[0]);
    ans.push_back(graph_cnt[1]);
    ans.push_back(graph_cnt[2]);
    return ans;
}
