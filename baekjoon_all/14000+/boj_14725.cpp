// Solve 2023-07-03
// Update 2024-10-21

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

struct Trie{
    map<string, Trie*> children;

    void insert(vector<string> &rooms, int idx) {
        if (idx == size(rooms)) return;

        if (children.find(rooms[idx]) == children.end()) {
            Trie* trie = new Trie;
            children[rooms[idx]] = trie;
        }

        children[rooms[idx]]->insert(rooms, idx + 1);
    }

    void dfs(int depth) {
        for (auto it = children.begin(); it != children.end(); it++) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }

            cout << it->first << '\n';
            it->second->dfs(depth + 1);
        }
    }

    ~Trie() {
        for (auto it = children.begin(); it != children.end(); it++) {
            delete it->second;
        }
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    Trie* root = new Trie;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<string> rooms(k);

        for (string &room : rooms) {
            cin >> room;
        }

        root->insert(rooms, 0);
    }

    root->dfs(0);

    delete root;

    return 0;
}
