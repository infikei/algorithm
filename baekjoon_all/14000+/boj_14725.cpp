// Solve 2023-07-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Node{
    map<string, Node*> child;
    map<string, Node*>::iterator it;

    ~Node() {
        for (it = child.begin(); it != child.end(); it++) {
            delete it->second;
        }
    }

    void insert(vector<string> vec, int idx = 0) {
        if (idx == SIZE(vec)) return;

        it = child.find(vec[idx]);

        if (it == child.end()) {
            Node* n = new Node;
            child.insert({ vec[idx], n });
            n->insert(vec, idx + 1);
        }
        else {
            it->second->insert(vec, idx + 1);
        }
    }

    void print(int depth = 0) {
        for (it = child.begin(); it != child.end(); it++) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << it->first << '\n';
            it->second->print(depth + 1);
        }
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    Node* root = new Node;

    for (int ni = 0; ni < n; ni++) {
        int k;
        cin >> k;

        vector<string> vec(k);
        for (int ki = 0; ki < k; ki++) {
            cin >> vec[ki];
        }

        root->insert(vec);
    }

    root->print();

    delete root;

    return 0;
}
