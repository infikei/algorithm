// Solve 2023-02-11
// Update 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int d(int x) { return (x * 2) % 10000; }

int s(int x) { return (x == 0 ? 9999 : (x - 1)); }

int l(int x) { return x % 1000 * 10 + x / 1000; }

int r(int x) { return x % 10 * 1000 + x / 10; }

int dslr(int x, int type) {
    if (type == 0) return d(x);
    if (type == 1) return s(x);
    if (type == 2) return l(x);
    return r(x);
}

void bfs(int a, int b, vector<int> &parent) {
    queue<int> bfs_que;
    bfs_que.push(a);
    parent[a] = a;

    while (!bfs_que.empty()) {
        for (int i = 0, ie = SIZE(bfs_que); i < ie; i++) {
            int now = bfs_que.front();
            bfs_que.pop();

            for (int type = 0; type < 4; type++) {
                int next = dslr(now, type);

                if (next == b) {
                    parent[next] = now;
                    return;
                }

                if (parent[next] == -1) {
                    parent[next] = now;
                    bfs_que.push(next);
                }
            }
        }
    }
}

void find_path(int a, int b, vector<int> &parent, string &path) {
    int cur = b;

    while (cur != a) {
        int prev = parent[cur];
        char ch;

        if (d(prev) == cur) ch = 'D';
        else if (s(prev) == cur) ch = 'S';
        else if (l(prev) == cur) ch = 'L';
        else ch = 'R';

        path.push_back(ch);
        cur = prev;
    }

    reverse(path.begin(), path.end());
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        cin >> a >> b;

        vector<int> parent(10000, -1);
        string path;
        bfs(a, b, parent);
        find_path(a, b, parent, path);

        cout << path << '\n';
    }

    return 0;
}
