// Solve 2024-01-14

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int parent = 0;
    int children[2] = { 0 };
};

Node tree[10001];
bool visited[10001];

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int v, e, a, b;
        cin >> v >> e >> a >> b;

        for (int u = 1; u <= v; u++) {
            tree[u].parent = 0;
            tree[u].children[0] = 0;
            tree[u].children[1] = 0;
            visited[u] = false;
        }

        for (int i = 0; i < e; i++) {
            int parent, child;
            cin >> parent >> child;

            tree[child].parent = parent;

            if (tree[parent].children[0] == 0) {
                tree[parent].children[0] = child;
            }
            else {
                tree[parent].children[1] = child;
            }
        }

        int cur = a;

        while (cur != 1) {
            visited[cur] = true;
            cur = tree[cur].parent;
        }

        cur = b;

        while (!visited[cur] && cur != 1) {
            cur = tree[cur].parent;
        }

        int common_parent = cur;
        int sub_tree_size = 1;
        queue<int> bfs_que;
        bfs_que.push(common_parent);

        while (!bfs_que.empty()) {
            int cur = bfs_que.front();
            bfs_que.pop();

            int nxt = tree[cur].children[0];

            if (nxt != 0) {
                sub_tree_size++;
                bfs_que.push(nxt);
            }

            nxt = tree[cur].children[1];

            if (nxt != 0) {
                sub_tree_size++;
                bfs_que.push(nxt);
            }
        }

        cout << '#' << ti << ' ' << common_parent << ' ' << sub_tree_size << '\n';
    }

    return 0;
}
