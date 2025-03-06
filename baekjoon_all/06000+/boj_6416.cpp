// Solve 2025-03-05

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

int coordinate_compression(vector<pii> &input) {
    vector<int> vec;

    for (pii &p : input) {
        vec.push_back(p.first);
        vec.push_back(p.second);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (pii &p : input) {
        p.first = lower_bound(vec.begin(), vec.end(), p.first) - vec.begin();
        p.second = lower_bound(vec.begin(), vec.end(), p.second) - vec.begin();
    }

    return vec.size();
}

bool dfs(int cur, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[cur] = true;

    for (int &nxt : adj[cur]) {
        if (visited[nxt]) {
            return false;
        }

        bool nxt_res = dfs(nxt, adj, visited);

        if (!nxt_res) {
            return false;
        }
    }

    return true;
}

bool is_tree(vector<pii> &input, int node_cnt) {
    if (node_cnt <= 0) {
        return true;
    }

    vector<vector<int>> adj(node_cnt, vector<int>());
    vector<int> in_degree(node_cnt, 0);

    for (pii &p : input) {
        adj[p.first].push_back(p.second);
        in_degree[p.second]++;
    }

    int root = -1;

    for (int u = 0; u < node_cnt; u++) {
        // 노드로 들어오는 간선이 2개 이상이면 트리가 아니다.
        if (in_degree[u] >= 2) {
            return false;
        }

        // 들어오는 간선이 없으면 루트 노드이다.
        if (in_degree[u] == 0) {
            // 루트 조건을 만족하는 노드가 2개 이상이면 트리가 아니다.
            if (root != -1) {
                return false;
            }

            root = u;
        }
    }

    // 루트 조건을 만족하는 노드가 없으면 트리가 아니다.
    if (root == -1) {
        return false;
    }

    vector<bool> visited(node_cnt, false);

    return dfs(root, adj, visited);
}

int main() {
    FASTIO;

    int testcase_num = 0;

    while (true) {
        bool end_of_input = false;
        vector<pii> input;

        while (true) {
            int u, v;
            cin >> u >> v;

            if (u <= 0 && v <= 0) {
                if (u < 0 && v < 0) {
                    end_of_input = true;
                }

                break;
            }

            input.emplace_back(u, v);
        }

        if (end_of_input) break;

        int node_cnt = coordinate_compression(input);

        if (is_tree(input, node_cnt)) {
            cout << "Case " << ++testcase_num << " is a tree." << '\n';
        }
        else {
            cout << "Case " << ++testcase_num << " is not a tree." << '\n';
        }
    }

    return 0;
}
