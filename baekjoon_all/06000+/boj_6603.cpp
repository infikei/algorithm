// Solve 2023-03-13

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

int k;
vector<int> s(12), ans(6);

void dfs(int depth = 0, int cur = 0) {
    if (depth == 6) {
        for (auto a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i < k; i++) {
        ans[depth] = s[i];
        dfs(depth + 1, i + 1);
    }
}

int main() {
    FASTIO;

    bool first_iter = true;
    while (true) {
        if (first_iter) first_iter = false;
        else cout << '\n';

        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        dfs();
    }

    return 0;
}
