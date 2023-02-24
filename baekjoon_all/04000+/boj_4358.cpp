// Solve 2022-09-01
// Update 2023-02-08

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

int main() {
    FASTIO;

    string tree;
    map<string, int> tree_cnt;
    int trees_cnt = 0;

    while (getline(cin, tree)) {
        trees_cnt++;
        tree_cnt[tree]++;
    }

    SETPRECISION(4);

    for (auto it = tree_cnt.begin(); it != tree_cnt.end(); it++) {
        cout << it->first << ' ' << (it->second * 100.0 / trees_cnt) << '\n';
    }

    return 0;
}