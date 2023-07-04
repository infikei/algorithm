// Solve 2023-07-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int CHILD_MAX_SIZE = 26;

struct Node{
    bool is_end;
    int child_cnt;
    Node* child[CHILD_MAX_SIZE];

    Node() : is_end(false), child_cnt(0) {
        for (int i = 0; i < CHILD_MAX_SIZE; i++) {
            child[i] = nullptr;
        }
    }
    ~Node() {
        for (int i = 0; i < CHILD_MAX_SIZE; i++) {
            if (child[i] != nullptr) {
                delete child[i];
            }
        }
    }

    void insert(string s, int idx = 0) {
        if (idx == SIZE(s)) {
            is_end = true;
            child_cnt++;
            return;
        }

        int k = s[idx] - 'a';

        if (child[k] == nullptr) {
            child[k] = new Node();
            child_cnt++;
        }
        child[k]->insert(s, idx + 1);
    }

    int dfs(int depth = 0) {
        int res = 0;

        if (is_end) res += depth;

        int ndepth = depth;
        if (depth == 0 || child_cnt >= 2) ndepth++;

        for (int i = 0; i < CHILD_MAX_SIZE; i++) {
            if (child[i] != nullptr) {
                res += child[i]->dfs(ndepth);
            }
        }

        return res;
    }
};

int main() {
    FASTIO;

    SETPRECISION(2);

    int n;
    while (cin >> n) {
        Node* root = new Node;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            root->insert(s);
        }

        int dfs_sum = root->dfs();

        double ans = (double)dfs_sum / n;
        cout << round(ans * 100) / 100 << '\n';

        delete root;
    }

    return 0;
}
