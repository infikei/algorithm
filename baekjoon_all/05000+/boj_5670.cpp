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
    map<char, Trie*> children;
    bool ended_flag;

    Trie() : ended_flag(false) {
    }

    ~Trie() {
        for (auto it = children.begin(); it != children.end(); it++) {
            delete it->second;
        }
    }

    void insert(string &s, int idx) {
        if (idx == size(s)) {
            ended_flag = true;
            return;
        }

        if (children.find(s[idx]) == children.end()) {
            Trie* child = new Trie;
            children[s[idx]] = child;
        }

        children[s[idx]]->insert(s, idx + 1);
    }

    int dfs(int depth) {
        int res = 0;

        if (ended_flag) {
            res += depth;
        }

        int ndepth = depth;

        if (depth == 0 || size(children) >= 2 || (size(children) == 1 && ended_flag)) {
            ndepth++;
        }

        for (auto it = children.begin(); it != children.end(); it++) {
            res += it->second->dfs(ndepth);
        }

        return res;
    }
};

int main() {
    FASTIO;
    setp(2);

    int n;

    while (cin >> n) {
        Trie* root = new Trie;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            root->insert(s, 0);
        }

        int ans_sum = root->dfs(0);
        double ans = ans_sum / (double) n;
        println(ans);

        delete root;
    }

    return 0;
}
