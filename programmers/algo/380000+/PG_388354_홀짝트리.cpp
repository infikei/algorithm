// Solve 2025-02-08 (대회 Solve)
// Update 2025-03-25

#include <string>
#include <vector>

using namespace std;

vector<int> adj[1000001];

int check_tree(int cur, int par, int tree_type) {
    int children_cnt = adj[cur].size() - (par == -1 ? 0 : 1);

    if (tree_type != (cur % 2 != children_cnt % 2)) return 2;

    for (int &nxt : adj[cur]) {
        if (nxt == par) continue;
        if (check_tree(nxt, cur, tree_type) == 2) return 2;
    }

    return tree_type;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2);

    for (vector<int> &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    for (int &root : nodes) {
        int tree_type = (root % 2 != adj[root].size() % 2);
        tree_type = check_tree(root, -1, tree_type);

        if (tree_type < 2) answer[tree_type]++;
    }

    return answer;
}
