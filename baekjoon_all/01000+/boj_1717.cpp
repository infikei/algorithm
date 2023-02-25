// Solve 2022-09-17
// Update 2023-02-14

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1000000;
int n, m, parent[MAX_N + 1];

int get_parent(int k) {
    if (parent[k] == k) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        int pa = get_parent(a);
        int pb = get_parent(b);

        if (cmd == 0) {
            parent[pa] = pb;
        }
        else {
            if (pa == pb) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}